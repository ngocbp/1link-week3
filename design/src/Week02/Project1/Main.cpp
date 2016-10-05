#include<iostream>
#include"Student.h"
#include"StudentController.h"
#include"View.h"
#include<list>
using namespace std;
int main() {
	string path = "C:/Users/hongc/Documents/Visual Studio 2015/Projects/Student/Student2/output.txt";
	View v;
	StudentController sc;
	int choice;
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
			sc.add(v.showAdd(), path);
			break;
		}
		case 3: {//edit
			system("cls");
			sc.edit(v.showSearchFrm());
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
				v.showList(sc.searchID());
				break;
			}
			case 2: {//search name
				system("cls");
				v.showList(sc.searchName());
				break;
			}
			case 3: {
				system("cls");
				v.showList(sc.searchSum());
				break;
			}
			case 4: {
				system("cls");
				v.showList(sc.searchMath());
				break;
			}
			case 5: {
				system("cls");
				v.showList(sc.searchPhys());
				break;
			}
			case 6: {
				system("cls");
				v.showList(sc.searchChem());
				break;
			}
			default:
				break;
			}
			break;
		}
		case 6: {
			system("cls");
			sc.statistical();
			break;
		}
		default:
			break;
		}
		system("pause");
	}
}