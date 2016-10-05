#include<iostream>
#include<string>
#include<list>
#include"View.h"
using namespace std;
int View::showMenu(){
	int choice;
	cout << "MENU:" << endl;
	cout << "1_Add student" << endl;
	cout << "2_Edit student" << endl;
	cout << "3_Delete student" << endl;
	cout << "4_Search" << endl;
	cout << "5_Statistical" << endl;
	cin >> choice;
	return choice;
};
Student View::showAdd() {
	Student st;
	int a; 
	string b, c, d; 
	int x, y, z;
	cout << "Id: "; cin >> a;
	st.setid(a);
	cout << "Name: "; 
	fflush(stdin);
	getline(cin,b);
	st.setname(b);
	cout << "Address: "; 
	fflush(stdin);
	getline(cin, c);
	st.setname(c);
	cout << "Sex: "; 
	fflush(stdin);
	getline(cin, d);
	st.setname(d);
	cout << "Math: "; cin >> x;
	st.setmath(x);
	cout << "Physic: "; cin >> y;
	st.setmath(y);
	cout << "Chemistry: "; cin >> z;
	st.setmath(z);
	return st;
};
int View::showSearch() {
	int search;
	cout << "1.Search by ID" << endl;
	cout << "2.Search by name" << endl;
	cout << "3.Search by sum" << endl;
	cout << "4.Search by math" << endl;
	cout << "5.Search by phys" << endl;
	cout << "6.Search by chem" << endl;
	cout << "your choice is...";
	cin >> search;
	return search;

};
void View::showList(list<Student> list1) {
	list<Student>::iterator it;
	for (it = list1.begin(); it != list1.end(); it++) {
		cout << (*it).getid() << " " << (*it).getname() << " " << (*it).getaddress() << " " << (*it).getsex() << " ";
		cout << (*it).getmath() << " " << (*it).getphys() << " " << (*it).getchem() << endl;
	}
};
int View::showSearchFrm() {
	cout << "Enter ID: ";
	int id;
	cin >> id;
	return id;
};
Student View::showEdit(Student st)
{
	cout << "Student: " << endl;
	cout << "ID: " << st.getid();
	cout << "\nName: " << st.getname();
	cout << "\nAddress: " << st.getaddress();
	cout << "\nSex: " << st.getsex();
	cout << "\nMath: " << st.getmath();
	cout << "\nPhys: " << st.getphys();
	cout << "\nChem: " << st.getchem();
	cout << "\ndo you want edit...";
	char c;
	cin >> c;
	if (c == 'y' || c == 'Y') {
		cout << "New infor: " << endl;
		return showAdd();
	}
}
void View::statistical(int n, int a, int b, int c, int d)
{
	cout << "Co tong so " << n << " sinh vien trong do co: " << endl;
	cout << a << " sinh vien co diem < 15" << endl;
	cout << b << " sinh vien co diem tu 15 den 20" << endl;
	cout << c << " sinh vien co diem tu 20 den 25" << endl;
	cout << d << " sinh vien co diem > 25" << endl;
}