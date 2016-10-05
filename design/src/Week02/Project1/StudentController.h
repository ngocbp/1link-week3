#pragma once
#include"Student.h"
#include "DAO.h"
#include<iostream>
class StudentController
{
public:
	bool add(Student, string);
	void showAll();
	StudentController();
	list<Student> searchID();
	list<Student> searchName();
	list<Student> searchSum();
	list<Student> searchMath();
	list<Student> searchPhys();
	list<Student> searchChem();
	bool edit(int);
	bool del();
	void statistical();
	~StudentController();
};
