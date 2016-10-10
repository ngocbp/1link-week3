#include "DAO.h"
#include<string>
#include<fstream>
#include<mutex>

mutex mu;

void DAO::writeFileThread(string path, string s)
{
	mu.lock();
	fstream f;
	f.open(path, ios::out | ios::app);
	f << s;
	f.close();
	cout << "new string: " << s << endl;
	mu.unlock();
}

string DAO::readFileThread(string path)
{
	fstream f;
	string s, line;
	f.open(path, ios::in);
	while (getline(f, line)) {
		s += line + "\n";
	}
	return s;
}

bool DAO::writeFile(Student st, string path)
{
	mu.lock();
	fstream f;
	f.open(path, ios::out | ios::app);
	f << st.getid() << "\t" << st.getname() << "\t" << st.getaddress() << "\t" << st.getsex() << "\t";
	f << st.getmath() << "\t" << st.getphys() << "\t" << st.getchem() << endl;
	f.close();
	return true;
	mu.unlock();
}

string DAO::readFile()
{
	string out, line;
	fstream f;
	f.open("output.txt", ios::in);
	while (getline(f, line)) {
		out += line + "\n";
	}
	return out;
}

list<Student> DAO::readList(string path)
{
	list<Student> list;
	Student st;
	string line;
	fstream f;
	f.open(path, ios::in);
	int id;
	string name, address, sex;
	int math, phys, chem;
	while (getline(f, line)) {
		bool flag = true;
		try
		{
			int p = line.find("\t");
			id = stoi(line.substr(0, p)); st.setid(id);
			line = line.substr(p + 1);
			name = line.substr(0, p).c_str(); st.setname(name);
			line = line.substr(p + 1);
			address = line.substr(0, p).c_str(); st.setaddress(address);
			line = line.substr(p + 1);
			sex = line.substr(0, p); st.setsex(sex);
			line = line.substr(p + 1);
			math = stoi(line.substr(0, p)); st.setmath(math);
			line = line.substr(p + 1);
			phys = stoi(line.substr(0, p)); st.setphys(phys);
			line = line.substr(p + 1);
			chem = stoi(line.substr(0, p)); st.setchem(chem);
			list.push_back(st);
		}
		catch (const std::exception&)
		{
			flag = false;
		}
		if (flag == false) {
			continue;
		}
	}
	return list;
}

DAO::DAO()
{
}


DAO::~DAO()
{
}