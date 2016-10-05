#pragma once
#include<iostream>
#include"Diem.h"
using namespace std;
class Student
{
private:
	int id;
	string name;
	string address;
	string sex;
	int math;
	int phys;
	int chem;
public:
	Student();
	~Student();
	void setid(int);
	int getid();
	void setname(string);
	string getname();
	void setaddress(string);
	string getaddress();
	void setsex(string);
	string getsex();
	void setmath(int);
	int getmath();
	void setphys(int);
	int getphys();
	void setchem(int);
	int getchem();
	int getSum(int, int, int);
	void input();
	void output();
	void sort();
	Student(int, string, string, string, string, int, int, int);
};
