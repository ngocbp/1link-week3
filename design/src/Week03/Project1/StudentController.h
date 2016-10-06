#pragma once
#include"Student.h"
#include "DAO.h"
#include<iostream>
class StudentController
{
public:
	void add(string);	
	void showAll();
	list<Student> searchID();
	list<Student> searchName();
	list<Student> searchSum();
	list<Student> searchMath();
	list<Student> searchPhys();
	list<Student> searchChem();
	bool edit();
	bool del();
	void statistical();
	StudentController();
	//~StudentController();
};
