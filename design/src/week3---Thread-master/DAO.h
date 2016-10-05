#pragma once
#include<fstream>
#include "Student2.h"
#include <list>
class DAO
{
public:
	bool writeFile(Student2, string);
	string readFile();
	list<Student2> readList(string);
	DAO();
	~DAO();
};

