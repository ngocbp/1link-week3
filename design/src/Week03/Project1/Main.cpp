#include<iostream>
#include<fstream>
#include<string>
#include<thread>
#include<Windows.h>
#include<list>

#include <cerrno>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

string checkPoint;

void writeFile(string path, string s) {
	fstream f;
	f.open(path, ios::out | ios::app);
	f << s;
	f.close();
	cout << "new string: " << s << endl;
}

string readFile(string path) {
	fstream f;
	string s, line;
	f.open(path, ios::in);
	while (getline(f, line)) {
		s += line + "\n";
	}
	return s;
}

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d%H%M%S", &tstruct);
	string date_now = (string)buf;
	return date_now;
}

list<string> load() {
	list<string> list;
	string path = "C:\\Users\\phung\\OneDrive\\Documents\\Visual Studio 2015\\Projects\\Week02\\demoThread\\content\\";
	string filter = "*.txt";
	string full = path + filter;

	WIN32_FIND_DATA fileName;
	HANDLE hFile;
	hFile = FindFirstFile(full.c_str(), &fileName);
	do {
		string link = path + fileName.cFileName;
		list.push_back(link);

	} while (FindNextFile(hFile, &fileName) > 0);
	return list;
}

void checkNewFile() {
	list<string> listSourceFile = load();
	char timeStr[100] = "";
	struct stat buf;
	string dateBuf;
	string timeBuf;
	while (!listSourceFile.empty()) {
		string str = listSourceFile.back();//lay 1 link de so sanh
		listSourceFile.pop_back();

		const char* cstr = str.c_str();
		if (!stat(cstr, &buf)) {
			strftime(timeStr, 100, "%Y/%m/%d %H:%M:%S", localtime(&buf.st_mtime));
			string s(timeStr);
			if (s > checkPoint) {
				system("cls");
				cout << str << endl;
				string data = readFile(str);
				if (data == "") {
					cout << "new file is empty" << endl;
				}
				else {
					writeFile("note.txt", data);
				}
			}
		}
		else {
			continue;
		}
	}
	checkPoint = currentDateTime();
	Sleep(10000);
	checkNewFile();
}


int main() {
	checkPoint = currentDateTime();
	thread reload(checkNewFile);
	string s;
	while (s != "exit") {
		cout << "cin >> ";
		cin >> s;
		if (s == "exit") {
			reload.detach();
			break;
		}
		else
		{
			writeFile("note.txt", s);
		}
	}
	return 0;
}