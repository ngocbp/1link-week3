#pragma once
#include<iostream>
using namespace std;
class Diem {
private:
	int math;
	int phys;
	int chem;
public:
	Diem();
	void setmath(int);
	int getmath();
	void setphys(int);
	int getphys();
	void setchem(int);
	int getchem();
};