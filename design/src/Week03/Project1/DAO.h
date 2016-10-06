#pragma once
#include<fstream>
#include "Student.h"
#include <list>
class DAO
{
public:
	bool writeFile(Student, string);
	string readFile();
	list<Student> readList(string);
	DAO();
	~DAO();
};