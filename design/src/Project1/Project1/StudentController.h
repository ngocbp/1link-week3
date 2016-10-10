#pragma once
#include"Student.h"
#include "DAO.h"
#include<iostream>
class StudentController
{
public:
	void add(string);	
	void showAll();
	void sort(list<Student>);
	void swap(Student, Student);
	void searchID();
	void searchName();
	void searchSum();
	void searchMath();
	void searchPhys();
	void searchChem();
	bool checkID(int);
	bool edit();
	bool del();
	void statistical();
	StudentController();
	//~StudentController();
};
