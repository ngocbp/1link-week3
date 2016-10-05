#include "Student2.h"
#include "View2.h"
#include "StudentCtr.h"
#include "DAO.h"
#include <iostream>
#include <list>
#include <vector>
#include <Windows.h>

using namespace std;
vector<string> listFile;

void WINAPI list1() {
	string path = "C:\\Users\\phung\\OneDrive\\Documents\\Visual Studio 2015\\Projects\\week3---Thread-master\\content\\";
	string search = "*.txt";
	string fullLink = path + search;
	WIN32_FIND_DATA findData;
	HANDLE hFind;
	
	while (1) {
		hFind = FindFirstFile(fullLink.c_str(), &findData);
		string line;
		do {
			string file_path = path + findData.cFileName;
			auto it = std::find(listFile.begin(), listFile.end(), file_path);
			if (it == listFile.end()) {

				DAO dao;
				list<Student2> list1 = dao.readList(file_path.c_str());
				list<Student2>::iterator it;
				for (it = list1.begin(); it != list1.end(); it++) {
					dao.writeFile(*it, "output.txt");
				}
			}
		} while (FindNextFile(hFind, &findData) > 0);
		Sleep(3000);
	}
}

int main() {
	string path = "C:/Users/phung/OneDrive/Documents/Visual Studio 2015/Projects/week3---Thread-master/output.txt";
	View2 v;
	StudentCtr sc;
	int choice;
	HANDLE handel = CreateThread(0, NULL, (LPTHREAD_START_ROUTINE)list1, 0, NULL, 0);
	while (1) {
		choice = v.showMenu();
		switch (choice)
		{
		case 1: {//show all
			system("cls");
			sc.showAll();
			break;
		}
		case 2: {//add
			system("cls"); 		
			sc.add(path);
			break;
		}
		case 3: {//edit
			system("cls");
			sc.edit();
			break;
		}
		case 4: {//delete
			system("cls");
			sc.del();
			break;
		}
		case 5: {//search
			system("cls");		
			switch (v.showSearch())
			{
			case 1: {//search id
				system("cls");
				sc.searchID();
				break;
			}
			case 2: {//search name
				system("cls");
				sc.searchName();
				break;
			}
			case 3: {//search sum
				system("cls");
				sc.searchSum();
				break;
			}
			case 4: {//search math
				system("cls");
				sc.searchMath();
				break;
			}
			case 5: {//search phys
				system("cls");
				sc.searchPhys();
				break;
			}
			case 6: {//search chem
				system("cls");
				sc.searchChem();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 6: {//thong ke
			system("cls");
			sc.thongke();
			break;
		}
		default:
			break;
		}
		system("pause");
	}
}