#include "Pair.h"
#include "File.h" 
#include <iostream> 
#include <fstream>
#include <string> 
#include <Windows.h>
using namespace std;

int main() 
{
	Pair p, temp;
	int k, c, num, count;
	double plus;
	char file_name[30];
	do {
		system("pause");
		system("cls");
		cout << "1. Create";
		cout << "\n2. Print";
		cout << "\n3. Delete pair";
		cout << "\n4. Add pair";
		cout << "\n0. Out\n";
		cin >> c;
		switch (c) 
		{
		case 1:
			cout << "Name of file: "; 
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)
				cout << "Error create file\n";
			break;
		case 2:
			cout << "Name of file: "; 
			cin >> file_name;
			k = print_file(file_name); 
			if (k == 0) cout << "Empty file\n";
			if (k < 0) cout << "Can't read file\n"; 
			break;
		case 3:
			cout << "Name of file: "; cin >> file_name;
			cin >> temp;
			k = del_file(file_name, temp);
			if (k < 0)cout << "File don't read\n";
			break;
		case 4:
			cout << "Name of file: "; 
			cin >> file_name;
			cout << "Num: "; 
			cin >> num;
			cout << "How many: "; 
			cin >> count;
			k = add_file(file_name, num, count);
			if (k < 0) cout << "Can't read file\n";
			if (k == 0) k = add_end(file_name, count);
			break;
		case 5:
			cout << "Name of file: "; 
			cin >> file_name;
			cout << "How much do you want to add?: ";
			cin >> plus;
			k = change_file(file_name, plus);
			if (k < 0) cout << "Can't read file\n";
			break;
		}
	} while (c != 0);
	return 0;
}
