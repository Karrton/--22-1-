#include <iostream>
#include <string>
using namespace std;
struct data_list {
	int x;
	string s;
};
struct List {
	data_list rec;
	List* Next = nullptr, * Prev = nullptr;
};
List* Head = 0, * Last = 0;
void Add(int x, string s, List* r) 
{
	r = new List;
	r->rec.x = x;
	r->rec.s = s;
	r->Next = 0;
	r->Prev = 0;
	if (Last)
	{
		Last->Next = r;
		r->Prev = Last;
	}
	if (!Head)
		Head = r;
	Last = r;
}
void Write(int &size)
{
	cout << "Возраст:";
	List* temp = Head;
	for (int i = 0; i < size; i++)
	{
		cout.width(10);
		cout << temp->rec.x;
		temp = temp->Next;
	}
	temp = Head;
	cout << endl;
	cout << "Имя:    ";
	for (int i = 0; i < size; i++)
	{
		cout.width(10);
		cout << temp->rec.s;
		temp = temp->Next;
	}
	cout << endl;
}
void Write_rev(int &size) 
{
	cout << "Возраст:";
	List* temp = Last;
	for (int i = 0; i < size; i++)
	{
		cout.width(10);
		cout << temp->rec.x;
		temp = temp->Prev;
	}
	temp = Last;
	cout << endl;
	cout << "Имя:    ";
	for (int i = 0; i < size; i++)
	{
		cout.width(10);
		cout << temp->rec.s;
		temp = temp->Prev;
	}
	cout << endl;
}
void Clear() 
{
	if (!Head)
		return;
	for (Last = Head->Next; Last; Last = Last->Next)
	{
		delete Last->Prev;
		Head = Last;
	}
	delete Head;
}
string make_name()
{
	string name;
	int size = 7;
	name += 65 + rand() % 25;
	for (int i = 0; i < size - 1; i++)
		name += 97 + rand() % 25;
	return name;
}
void del(int x, int& size, List* temp) 
{
	if ((x == 1) && (Head->Next))
	{
		List* temp = Head;
		Head = Head->Next;
		Head->Prev = NULL;
		delete temp;
		--size;
		return;
	}
	else if ((x == 1) && (Head == Last))
	{
		Head->Next = NULL;
		Head = NULL;
		delete Head;
		--size;
		return;
	}
	if (x == size) 
	{
		List* temp = Last;
		Last = Last->Prev;
		Last->Next = NULL;
		delete temp;
		--size;
		return;
	}
	List* temp2 = nullptr;
	temp2 = temp;
	temp2->Prev->Next = temp->Next;
	temp2->Next->Prev = temp->Prev;
	delete temp;
	--size;
}
void getout()
{
	cout << "Нажмите любую кнопку, чтобы перейти в меню." << endl;
	cin.get();
	return;
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	List* r = nullptr;
	List* r2 = nullptr;
	int size;
	int size2;
	string name;
	int a = 0;
	int choose;
	bool fl = true;
	bool flag = false;
	data_list* buff;
	while (true)
	{
		system("cls");
		cout << "=====Меню=====" << endl;
		cout << "Введите 1, чтобы создать и заполнить список." << endl;
		cout << "Введите 2, чтобы вывести список с начала." << endl;
		cout << "Введите 3, чтобы вывести список с конца." << endl;
		cout << "Введите 4, чтобы удалить данные по введённой фамилии." << endl;
		cout << "Введите 5, чтобы добавить данные перед введённым номером." << endl;
		cout << "Введите любое число, кромне представленных выше, чтобы выйти из программы." << endl;
		cout << "Введите команду - ";
		cin >> choose;
		cin.get();
		switch (choose)
		{
		case 1:
		{
			system("cls");
			Clear();
			fl = true;
			cout << "Данные о скольки людях внести? ";
			cin >> size;
			cin.get();
			for (int i = 0; i < size; i++)
				Add(rand() % 100, make_name(), r);
			fl = false;
			flag = true;
			getout();
			break;
		}
		case 2:
		{
			system("cls");
			if (flag)
			{
				cout << "Исходный список:" << endl;
				Write(size);
			}
			else
				cout << "Для начала нужно заполинть список." << endl;
			getout();
			break;
		}
		case 3:
		{
			system("cls");
			if (flag)
			{
				cout << "Исходный список:" << endl;
				Write_rev(size);
			}
			else
				cout << "Для начала нужно заполинть список." << endl;
			getout();
			break;
		}
		case 4:
		{
			system("cls");
			if (flag)
			{
				Write(size);
				cout << "Введите имя, чтобы удалить данные о этом челоеке - ";
				getline(cin, name);
				int check = 0;
				List* buff = nullptr;
				List* temp = Head;
				bool l = false;
				for (int i = 0; i < size; i++)
				{
					if (temp->rec.s == name)
					{
						del(check, size, temp);
						l = true;
						break;
					}
					temp = temp->Next;
				}
				system("cls");
				if (l)
					cout << "Данные удалены." << endl;
				else
					cout << "Данные по введённому ключу не найдены." << endl;
			}
			else
				cout << "Для начала нужно заполинть список." << endl;
			getout();
			break;
		}
		case 5:
		{
			system("cls");
			if (flag)
			{
				int val;
				cout << "Перед каким номером вставить данные о человеке? ";
				List* g = new List;
				g->rec.x = rand() % 100;
				g->rec.s = make_name();
				g->Next = 0;
				g->Prev = 0;
				List* temp = NULL;
				List* temp2 = NULL;
				cin >> val;
				cin.get();
				int a = 0;
				temp = Head;	
				for (int i = 0; i < val - 1; i++) 
					temp = temp->Next;
				if (val == 1)
				{
					g->Prev = 0;
					Head = g;
					g->Next = temp;
					temp->Prev = g;
				}
				else
				{
					temp = temp->Prev;
					temp2 = temp->Next;
					temp->Next = g;
					g->Next = temp2;
					g->Prev = temp;
					temp->Next = g;
					temp2->Prev = g;
				}
				++size;
			}
			else
				cout << "Для начала нужно заполинть список." << endl;
			getout();
			break;
		}
			default:
			{
				system("cls");
				Clear();
				return 0;
				break;
			}
		}
	}
	return 0;
}