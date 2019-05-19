#include"Person.h"
#include"ListPerson.h"
#include<string>
#include<iostream>
#include <fstream>
using namespace std;

int main() {
	ListPerson *LPS;
	LPS = new ListPerson();
	int n;
	char c;
	do
	{
		cout << "\n1. Hien thi danh sach Person";
		cout << "\n2. Them Person";
		cout << "\n3. Cap nhat thong tin Person";
		cout << "\n4. Xoa Person ";
		cout << "\n5. Tim kiem Person theo ma Person";
		cout << "\n6. Sap xep danh sach Person theo ma Person";
		cout << "\n CHON CONG VIEC:     " << endl;
		cout << "\n==========================" << endl;
		cin >> n;

		switch (n)
		{
		case 1:
			LPS->showPerson();
			break;
		case 2:
			LPS->addPerson();
			break;
		case 3:
			LPS->updatePerson();
			break;
		case 4:
			LPS->deletePerson();
			break;
		case 5:
			LPS->searchPerson();
			break;
		case 6:
			LPS->sortPerson();
			break;
		default:
			cout << "\n\nBan chon sai! moi ban chon lai: \n\n";
			break;
		}
	} while (n);
	return 0;
}
