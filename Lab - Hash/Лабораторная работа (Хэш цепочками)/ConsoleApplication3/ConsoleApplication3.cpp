#include <iostream>
#include <string>
#include <random>
#include <fstream>
using namespace std;
struct Data
{
	string name;
	string date;
	string pass;
};
struct List
{
	Data val;
	bool del = false;
	List* Next = 0;
};
struct Node
{
	List* Head = 0;
	List* Last = 0;
	int n = 0;
};

double generate_random()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double>dis(0.0, 1.0);
	return dis(gen);
}
double cof = generate_random();
int Hash(int val, int key)
{
	double buff = key * cof;
	int buff2 = buff;
	buff = buff - buff2;
	buff2 = buff * val;
	return buff2;
}
string make_name()
{
	string name;
	int size = 7;
	for (int j = 0; j < 3; j++)
	{
		name += 65 + rand() % 25;
		for (int i = 0; i < size - 1; i++)
			name += 97 + rand() % 25;
		name += ' ';
	}
	return name;
}
string make_num(bool check)
{
	string num;
	if (check)
	{
		int year = 2000 + rand() % 1000;
		int d = 1 + rand() % 12;
		num += to_string(d) + '.';
		if (d == 2)
		{
			if (year % 4 == 0)
				d = rand() % 29;
			else
				d = rand() % 28;
		}
		if ((d % 2 == 0) && (d != 2))
			d = rand() % 30;
		else
			d = rand() % 31;
		num += to_string(d) + '.';
		num += to_string(year);

	}
	else
	{
		for (int i = 0; i < 4; i++)
			num += 48 + rand() % 9;
		num += ' ';
		for (int i = 0; i < 6; i++)
			num += 48 + rand() % 9;
	}
	return num;
}
void add(Node arr[], List* temp)
{
	int a = Hash(12, (stoi(temp->val.date.substr(0, 2))));
	temp->val.name = make_name();
	temp->val.pass = make_num(false);
	if (!arr[a].Head)
	{
		arr[a].Head = temp;
		arr[a].Last = arr[a].Head;
		arr[a].Last->Next = 0;
	}
	else
	{
		arr[a].Last->Next = temp;
		arr[a].Last = temp;
		arr[a].Last->Next = 0;
	}
	arr[a].n += 1;
}
void del(Node arr[], int b, int g)
{
	int a = g;
	List* temp = 0;
	List* temp2 = 0;
	if (a == 1)
	{
		temp2 = arr[b].Head;
		arr[b].Head = temp2->Next;
		delete temp2;
		arr[b].n -= 1;
		return;
	}
	if (a == arr[b].n)
	{
		temp = arr[b].Head;
		temp2 = arr[b].Last;
		for (int i = 0; i < a - 2; i++)
			temp = temp->Next;
		arr[b].Last = temp;
		temp->Next = 0;
		delete temp2;
		arr[b].n -= 1;
		return;
	}
	temp2 = arr[b].Head;
	for (int i = 0; i < a - 2; i++)
		temp2 = temp2->Next;
	temp = temp2->Next;
	temp2->Next = temp2->Next->Next;
	delete temp;
	arr[b].n -= 1;
	return;
}
void show(Node arr[])
{
	for (int i = 0; i < 12; i++)
	{
		for (List* temp = arr[i].Head; temp;)
		{
			cout << temp->val.name << "\t";
			temp = temp->Next;
		}
		cout << endl;
		for (List* temp = arr[i].Head; temp;)
		{
			cout << temp->val.date << "\t\t\t";
			temp = temp->Next;
		}
		cout << endl;
		for (List* temp = arr[i].Head; temp;)
		{
			cout << temp->val.pass << "\t\t\t";
			temp = temp->Next;
		}
		cout << endl;
		for (List* temp = arr[i].Head; temp;)
		{
			if (!temp->del)
				cout << "Сохранено" << "\t\t\t";
			else
				cout << "Удалено  " << "\t\t\t";
			temp = temp->Next;
		}
		cout << endl;
		cout << "-----------------------" << endl;
	}
}

void main ()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество генерируемых данных - ";
	int size; 
	int choose;
	int val_del;
	int n_del = 0;
	int b = -1;
	int buff = 0;
	cin >> size;
	cin.get();
	Node arr[12]{};
	for (int i = 0; i < size; i++)
	{
		List* temp = new List;
		temp->val.date = make_num(true);
		add(arr, temp);
	}
	while (true)
	{
		system("cls");
		cout << "=====Меню=====" << endl;
		cout << "Введите 1, чтобы вывести всю таблицу (возможно некоректное отображение данных, при их больших объёмах)" << endl;
		cout << "Введите 2, чтобы удалить данные по ключу поиска (повторное использование с одинаковым числом удалит следующий после удалённого элнмент)" << endl;
		cout << "Введите 3, чтобы отменить последнее действие удаления" << endl;
		cout << "Введите 4, чтобы добавить элемент в таблицу" << endl;
		cout << "Введите любое число, кроме представленных выше, чтобы закончить работу, удалить и сохранить оставшиеся данные" << endl;
		cout << "Введите команду - ";
		cin >> choose;
		cin.get();
		switch (choose)
		{
			case 1:
			{
				system("cls");
				show(arr);
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 2:
			{
				system("cls");
				show(arr);
				cout << "Чтобы удалить данные какого-либо человека, введите месяц его рождения. Дата представлена в формате - мм.дд.гг" << endl;
				cin >> val_del;
				cin.get();
				bool flag = false;
				b = Hash(12, val_del);
				List* temp = arr[b].Head;
				for (int i = 0; i < arr[b].n; i++)
					if (val_del == stoi(temp->val.date.substr(0, 2)) && !temp->del)
					{
						temp->del = true;
						buff = i;
						flag = true;
					}
					else
						temp = temp->Next;
				++n_del;
				if (flag == false)
					cout << "Данные не найдены" << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 3:
			{
				system("cls");
				if (b < 12 && b >= 0)
				{
					List* temp = arr[b].Head;
					for (int i = 0; i < arr[b].n; i++)
						if (buff == i)
							temp->del = false;
						else
							temp = temp->Next;
					cout << "Последняя операция удаления отменена" << endl;
				}
				else
					cout << "Выполните операцию удаления файла" << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 4:
			{
				system("cls");
				List* temp = new List;
				temp->val.date = make_num(true);
				add(arr, temp);
				++size;
				cout << "Элемент добавлен" << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			default:
			{
				system("cls");
				if (n_del > size / 2)
					for (int i = 0; i < 12; i++)
					{
						int g = 0;
						List* temp = arr[i].Head;
						for (int j = 0; j < arr[i].n; j++)
						{
							++g;
							if (temp->del == true)
							{
								del(arr, i, g);
								j = 0;
								i = 0;
								g = 0;
							}
							else
								temp = temp->Next;
						}
					}
				ofstream file;
				file.open("rez.txt");
				for (int i = 0; i < 12; i++)
				{
					for (List* temp = arr[i].Head; temp;)
					{
						file << temp->val.name << "\t";
						temp = temp->Next;
					}
					file << endl;
					for (List* temp = arr[i].Head; temp;)
					{
						file << temp->val.date << "\t\t\t";
						temp = temp->Next;
					}
					file << endl;
					for (List* temp = arr[i].Head; temp;)
					{
						file << temp->val.pass << "\t\t\t";
						temp = temp->Next;
					}
					file << endl;
					file << "-----------------------" << endl;
				}
				return;
				break;
			}
		}
	}
}