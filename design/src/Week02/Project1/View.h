#pragma once
#include<iostream>
#include<list>
#include"Student.h"
using namespace std;
class View {
public:
	int showMenu();
	Student showAdd();
	int showSearch();
	void showList(list<Student>);
	int showSearchFrm();
	Student showEdit(Student);
	void statistical(int, int, int, int, int);
	View();
	~View();
};