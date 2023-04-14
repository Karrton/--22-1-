#include <iostream>
#include <string>
using namespace std;
struct Data
{
	int x;
};
struct List
{
	Data val;
	List* Next = nullptr;
};
List* Head = 0;
List* Last = 0;
void add()
{
	if (!Head)
	{
		Head = new List;
		Head->val.x = rand() % 10;
		Last = Head;
		Last->Next = 0;
	}
	else
	{
		List* temp = new List;
		temp->val.x = rand() % 10;
		Last->Next = temp;
		Last = temp;
		Last->Next = 0;
	}
}
void add_new(int a, int& size)
{
	List* temp = new List;
	List* temp2 = 0;
	temp->val.x = rand() % 10;
	if (a == 1)
	{
		temp2 = Head;
		Head = temp;
		temp->Next = temp2;
		return;
	}
	if (a == size + 1)
	{
		temp2 = Last;
		Last = temp;
		Last->Next = 0;
		temp2->Next = Last;
		return;
	}
	temp2 = Head;
	for (int i = 0; i < a - 2; i++)
		temp2 = temp2->Next;
	temp->Next = temp2->Next;
	temp2->Next = temp;
	return;
}
void del(int a, int& size)
{
	List* temp = 0;
	List* temp2 = 0;
	if (a == 1)
	{
		temp2 = Head;
		Head = temp2->Next;
		delete temp2;
		return;
	}
	if (a == size)
	{
		temp = Head;
		temp2 = Last;
		for (int i = 0; i < a - 2; i++)
			temp = temp->Next;
		Last = temp;
		temp->Next = 0;
		delete temp2;
		return;
	}
	temp2 = Head;
	for (int i = 0; i < a - 2; i++)
		temp2 = temp2->Next;
	temp = temp2->Next;
	temp2->Next = temp2->Next->Next;
	delete temp;
	return;
}
void show()
{
	for (List* temp = Head; temp;)
	{
		cout << temp->val.x << " ";
		temp = temp->Next;
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int choose;
	int size;
	while (true)
	{
		system("cls");
		cout << "Заполнить список - 1" << endl;
		cout << "Добавить элемент в список - 2" << endl;
		cout << "Удалить элемент - 3" << endl;
		cout << "Вывести список - 4" << endl;
		cout << "Очистить список - 5" << endl;
		cout << "Выйти из программы - любое другое число, кроме представленных выше" << endl;
		cout << "Введите команду - ";
		cin >> choose;
		cin.get();
		switch (choose)
		{
		case 1:
		{
			if (Head)
				for (int i = 0; i < size; i++)
					del(1, size);
			system("cls");
			cout << "Введите размер списка - ";
			cin >> size;
			cin.get();
			for (int i = 0; i < size; i++)
				add();
			cout << "Список создан" << endl;
			cout << "Нажмите Enter, чтобы перейти в меню" << endl;
			cin.get();
			break;
		}
		case 2:
		{
			system("cls");
			if (Head)
			{
				show();
				cout << "Введите номер добавляемого элемента - ";
				int a;
				cin >> a;
				cin.get();
				add_new(a, size);
				++size;
				cout << "Элемент добавлен" << endl;
			}
			else
				cout << "Список пуст, невозможно произвести данную операцию." << endl;
			cout << "Нажмите Enter, чтобы перейти в меню" << endl;
			cin.get();
			break;
		}
		case 3:
		{
			system("cls");
			if (Head)
			{
				show();
				cout << "Введите номер удаляемого элемента - ";
				int a;
				cin >> a;
				cin.get();
				del(a, size);
				--size;
				cout << "Элемент удалён" << endl;
			}
			else
				cout << "Список пуст, невозможно произвести данную операцию." << endl;
			cout << "Нажмите Enter, чтобы перейти в меню" << endl;
			cin.get();
			break;
		}
		case 4:
		{
			system("cls");
			if (Head)
				show();
			else
				cout << "Список пуст, невозможно произвести данную операцию." << endl;
			cout << "Нажмите Enter, чтобы перейти в меню" << endl;
			cin.get();
			break;
		}
		case 5:
		{
			system("cls");
			if (Head)
			{
				for (int i = 0; i < size; i++)
					del(1, size);
				cout << "Список очищен" << endl;
			}
			else
				cout << "Список пуст, невозможно произвести данную операцию." << endl;
			cout << "Нажмите Enter, чтобы перейти в меню" << endl;
			cin.get();
			break;
		}
		default:
		{
			system("cls");
			if (Head)
				for (int i = 0; i < size; i++)
					del(1, size);
			return 0;
			break;
		}
		}
	}
	return 0;
}