#include<iostream>
#include<string>
#include"Student.h"
using namespace std;
void Student::setid(int id1) {
	id = id1;
}
int Student::getid() {
	return id;
}
void Student::setname(string name1) {
	name = name1;
}
string Student::getname() {
	return name;
}
void Student::setaddress(string address1) {
	address = address1;
}
string Student::getaddress() {
	return address;
}
void Student::setsex(string sex1) {
	sex = sex1;
}
string Student::getsex() {
	return sex;
}
void Student::setmath(int math1) {
	math = math1;
}
int Student::getmath() {
	return math;
}
void Student::setphys(int phys1) {
	phys = phys1;
}
int Student::getphys() {
	return phys;
}
void Student::setchem(int chem1) {
	chem = chem1;
}
int Student::getchem() {
	return this->chem;
}
int Student::getSum(int math, int phys, int chem) {
	return math + phys + chem;
}
Student::Student() {

};
Student::Student(int id1, string name1, string address1, string sex1, int math1, int phys1, int chem1) {
	id = id1;
	name = name1;
	address = address1;
	sex = sex1;
	math = math1;
	phys = phys1;
	chem = chem1;
}