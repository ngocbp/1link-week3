#include "Student.h"
#include "View.h"
#include "StudentController.h"
#include "DAO.h"
#include <iostream>
#include <list>
#include<fstream>
#include <vector>
#include <Windows.h>
#include<thread>
#include <cerrno>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

vector<string> listFile;
string checkPoint;

void WINAPI list1() {
	string path = "C:\\Users\\phung\\OneDrive\\Documents\\Visual Studio 2015\\Projects\\Week02\\Project1\\content\\";
	string search = "*.txt";
	string fullLink = path + search;
	WIN32_FIND_DATA findData;
	HANDLE hFind;

	while (1) {
		hFind = FindFirstFile(fullLink.c_str(), &findData);
		string line;
		do {
			string file_path = path + findData.cFileName;
			auto it = std::find(listFile.begin(), listFile.end(), file_path);
			if (it == listFile.end()) {
				StudentController sc;
				DAO dao;
				list<Student> list1 = dao.readList(file_path.c_str());
				list<Student>::iterator it;
				for (it = list1.begin(); it != list1.end(); it++) {
					
					dao.writeFile(*it, "note.txt");
				}
			}
		} while (FindNextFile(hFind, &findData) > 0);
		Sleep(3000);
	}
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
	StudentController sc;
	DAO dao;
	string path = "C:\\Users\\phung\\OneDrive\\Documents\\Visual Studio 2015\\Projects\\Week02\\Project1\\content\\";
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
	DAO dao;
	while (!listSourceFile.empty()) {
		string str = listSourceFile.back();
		listSourceFile.pop_back();//lay 1 link de so sanh

		const char* cstr = str.c_str();
		if (!stat(cstr, &buf)) {
			strftime(timeStr, 100, "%Y%m%d%H%M%S", localtime(&buf.st_mtime));
			string s(timeStr);
			if (s > checkPoint) {
				system("cls");
				//cout<<str<<endl;
				string data = dao.readFileThread(str);
				if (data == "") {
					cout << "new file is empty" << endl;
				}
				else {
					StudentController sc;
					list<Student> list1 = dao.readList(str);
					list<Student>::iterator it;
					for (it = list1.begin(); it != list1.end(); it++)
					{
						if (sc.checkID((*it).getid())) {
							continue;
						}
						else {
							dao.writeFileThread("note.txt", data);
							//cout << "new string: " << data;
						}
					}
				}
			}
		}
		else {
			continue;
		}
	}
	checkPoint = currentDateTime();
	Sleep(20000);
	checkNewFile();
}

int main() {
	string path = "C:/Users/phung/OneDrive/Documents/Visual Studio 2015/Projects/Week02/Project1/output.txt";
	checkPoint = currentDateTime();
	thread reload(checkNewFile);
	View v;
	StudentController sc;
	int choice;
	
	while (1) {
		choice = v.showMenu();
		switch (choice)
		{
		case 1: {//show all
			system("cls");
			sc.showAll();
			break;
		}
		case 2: {//add
			system("cls");
			sc.add(path);
			break;
		}
		case 3: {//edit
			system("cls");
			sc.edit();
			break;
		}
		case 4: {//delete
			system("cls");
			sc.del();
			break;
		}
		case 5: {//search
			system("cls");
			switch (v.showSearch())
			{
			case 1: {//search id
				system("cls");
				sc.searchID();
				break;
			}
			case 2: {//search name
				system("cls");
				sc.searchName();
				break;
			}
			case 3: {//search sum
				system("cls");
				sc.searchSum();
				break;
			}
			case 4: {//search math
				system("cls");
				sc.searchMath();
				break;
			}
			case 5: {//search phys
				system("cls");
				sc.searchPhys();
				break;
			}
			case 6: {//search chem
				system("cls");
				sc.searchChem();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 6: {//statistical
			system("cls");
			sc.statistical();
			break;
		}
		default:
			break;
		}
		system("pause");
	}
}