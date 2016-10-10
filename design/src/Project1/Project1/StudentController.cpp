#include<iostream>
#include"StudentController.h"
#include"View.h"
#include"DAO.h"
#include<string>
using namespace std;
void StudentController::add(string path) {
	View v;
	Student st = v.showAdd();
	DAO dao;
	if (checkID(st.getid()))
	{
		cout << "Student exist";
	}
	else {
		if (dao.writeFile(st, "output.txt")) {
			cout << "add success" << endl;
		}
		else cout << "fail" << endl;
	}
	
}

void StudentController::showAll()
{
	DAO dao;
	View v;
	Student st;
	list<Student> list1 = dao.readList("ouput.txt");
	list<Student>::iterator it;
	for ( it = list1.begin(); it != list1.end(); it++)
	{
		st.setid((*it).getid());
		st.setname((*it).getname());
		st.setaddress((*it).getaddress());
		st.setsex((*it).getsex());
		st.setmath((*it).getmath());
		st.setphys((*it).getphys());
		st.setchem((*it).getchem());
		v.showOne(st);
	}
}

struct CompareBy
{
	const string SORT_FIELD;
	CompareBy(const string& sort_field = "name") :SORT_FIELD(sort_field)
	{
		/* validate sort_field */
	}

	bool operator()(Student& st1, Student& st2)
	{
		if (SORT_FIELD == "name")
			return st1.getname() < st2.getname();
		else if (SORT_FIELD == "sum")
			return st1.getmath() + st1.getphys() + st1.getchem() < st2.getmath() + st2.getphys() + st2.getchem();
		else if (SORT_FIELD == "id")
			return st1.getid() < st2.getid();
	}
};

void StudentController::sort(list<Student> list1)
{
	View v;
	switch (v.showSortMenu())
	{
	case 1: {//sort by id
		list1.sort(CompareBy("id"));
		v.showList(list1);
		break;
	}
	case 2: {//sort by name
		list1.sort(CompareBy("name"));
		v.showList(list1);
		break;
	}
	case 3: {//sort by sum
		list1.sort(CompareBy("sum"));
		v.showList(list1);
		break;
	}
	default:
		break;
	}
}

bool StudentController::edit() {
	DAO dao;
	View view;
	list<Student> list1;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	int id = view.showSearchFrm();
	for (it = list1.begin(); it != list1.end(); it++)
	{
		if ((*it).getid() == id)
		{
			Student st1, st2;
			st1.setid((*it).getid());
			st1.setname((*it).getname());
			st1.setaddress((*it).getaddress());
			st1.setsex((*it).getsex());
			st1.setmath((*it).getmath());
			st1.setphys((*it).getphys());
			st1.setchem((*it).getchem());
			st2 = view.showEdit(st1);
			(*it).setid(st2.getid());
			(*it).setname(st2.getname());
			(*it).setaddress(st2.getaddress());
			(*it).setsex(st2.getsex());
			(*it).setmath(st2.getmath());
			(*it).setphys(st2.getphys());
			(*it).setchem(st2.getchem());
		}
	}
	remove("output.txt");
	for (it = list1.begin(); it!= list1.end(); it++)
	{
		Student st;
		st.setid((*it).getid());
		st.setname((*it).getname());
		st.setaddress((*it).getaddress());
		st.setsex((*it).getsex());
		st.setmath((*it).getmath());
		st.setphys((*it).getphys());
		dao.writeFile(st,"output.txt");
	}
	return true;
}
bool StudentController::del() {
	DAO dao;
	View view;
	int id = view.showSearchFrm();
	list<Student> list1, result;
	list<Student>::iterator it;
	for ( it = list1.begin(); it != list1.begin();  it++)
	{
		if ((*it).getid() == id) {
			it = list1.erase(it);
		}
		if (it == list1.end()) break;
	}
	remove("output.txt");
	for (it = list1.begin(); it != list1.begin(); it++)
	{
		Student st;
		st.setid((*it).getid());
		st.setname((*it).getname());
		st.setaddress((*it).getaddress());
		st.setsex((*it).getsex());
		st.setmath((*it).getmath());
		st.setphys((*it).getphys());
		dao.writeFile(st,"output.txt");
	}
	return true;
}
void StudentController::searchID() {
	Student st;
	DAO dao;
	list<Student> list1, result;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	system("cls");
	int id;
	cout << "enter ID: ";
	cin >> id;
	for (it = list1.begin(); it != list1.end(); it++) {
		if ((*it).getid() == id) {
			st.setid((*it).getid());
			st.setname((*it).getname());
			st.setaddress((*it).getaddress());
			st.setsex((*it).getsex());
			st.setmath((*it).getmath());
			st.setphys((*it).getphys());
			result.push_back(st);
		}
	}
	sort(result);
}
void StudentController::searchName() {
	Student st;
	DAO dao;
	list<Student> list1, result;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	system("cls");
	string name;
	cout << "enter name: ";
	fflush(stdin);
	getline(cin, name);
	for (it = list1.begin(); it != list1.end(); it++) {
		if ((*it).getname() == name) {
			st.setid((*it).getid());
			st.setname((*it).getname());
			st.setaddress((*it).getaddress());
			st.setsex((*it).getsex());
			st.setmath((*it).getmath());
			st.setphys((*it).getphys());
			//Student st = Student((*it).getid(), (*it).getname(), (*it).getaddress(), (*it).getsex(), (*it).getmath(), (*it).getphys(), (*it).getchem());
			result.push_back(st);
		}
	}
	sort(result);
}
void StudentController::searchSum() {
	Student st;
	DAO dao;
	list<Student> list1, result;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	system("cls");
	int sum;
	cout << "enter Sum: ";
	cin >> sum;
	for (it = list1.begin(); it != list1.end(); it++) {
		    int sum1 = (*it).getmath() + (*it).getphys() + (*it).getchem();
		if (sum = sum1) {
			st.setid((*it).getid());
			st.setname((*it).getname());
			st.setaddress((*it).getaddress());
			st.setsex((*it).getsex());
			st.setmath((*it).getmath());
			st.setphys((*it).getphys());
			result.push_back(st);
		}
	}
	sort(result);
}
void StudentController::searchMath() {
	Student st;
	DAO dao;
	list<Student> list1, result;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	system("cls");
	int math;
	cout << "enter Math: ";
	cin >> math;
	for (it = list1.begin(); it != list1.end(); it++) {
		if ((*it).getmath() == math) {
			st.setid((*it).getid());
			st.setname((*it).getname());
			st.setaddress((*it).getaddress());
			st.setsex((*it).getsex());
			st.setmath((*it).getmath());
			st.setphys((*it).getphys());
			result.push_back(st);
		}
	}
	sort(result);
}

void StudentController::searchChem() {
	Student st;
	DAO dao;
	list<Student> list1, result;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	system("cls");
	int chem;
	cout << "enter Chem: ";
	cin >> chem;
	for (it = list1.begin(); it != list1.end(); it++) {
		if ((*it).getchem() == chem) {
			st.setid((*it).getid());
			st.setname((*it).getname());
			st.setaddress((*it).getaddress());
			st.setsex((*it).getsex());
			st.setmath((*it).getmath());
			st.setphys((*it).getphys());
			result.push_back(st);
		}
	}
	sort(result);
}
bool StudentController::checkID(int id)
{
	DAO dao;
	list<Student> list1 = dao.readList("output.txt");
	list<Student>::iterator it;
	for (it = list1.begin(); it != list1.end() ; it++)
	{
		if ((*it).getid() == id) {
			return true;
		}
	}
	return false;
}
void StudentController::searchPhys() {
	Student st;
	DAO dao;
	list<Student> list1, result;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	system("cls");
	int phys;
	cout << "enter Phys: ";
	cin >> phys;
	for (it = list1.begin(); it != list1.end(); it++) {
		if ((*it).getphys() == phys) {
			st.setid((*it).getid());
			st.setname((*it).getname());
			st.setaddress((*it).getaddress());
			st.setsex((*it).getsex());
			st.setmath((*it).getmath());
			st.setphys((*it).getphys());
			result.push_back(st);
		}
	}
	sort(result);
}
void StudentController::statistical()
{
	int n = 0, a = 0, b = 0, c = 0, d = 0;
	View v;
	DAO dao;
	list<Student> list1;
	list<Student>::iterator it;
	list1 = dao.readList("output.txt");
	for (it = list1.begin(); it != list1.end(); it++) {
		n++;
		int s = (*it).getmath() + (*it).getphys() + (*it).getchem();
		if (s < 15) { a++; }
		if (s >= 15 && s < 20) { b++; }
		if (s >= 20 && s < 25) { c++; }
		if (s >= 25) { d++; }
	}
	v.statistical(n, a, b, c, d);
}


StudentController::StudentController()
{
}