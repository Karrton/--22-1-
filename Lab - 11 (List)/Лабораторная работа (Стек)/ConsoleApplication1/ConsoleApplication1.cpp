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
void add_new()
{
	List* temp = new List;
	List* temp2 = 0;
	temp->val.x = rand() % 10;
	temp2 = Head;
	Head = temp;
	temp->Next = temp2;
	return;

}
void del(int &size)
{
	List* temp = 0;
	List* temp2 = 0;
	temp = Head;
	temp2 = Last;
	for (int i = 0; i < size - 2; i++)
		temp = temp->Next;
	Last = temp;
	temp->Next = 0;
	delete temp2;
	return;
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
		cout << "Заполнить стек - 1" << endl;
		cout << "Добавить элемент в стек - 2" << endl;
		cout << "Удалить элемент - 3" << endl;
		cout << "Вывести верхний элемент стека - 4" << endl;
		cout << "Вывести стек - 5" << endl;
		cout << "Очистить стек - 6" << endl;
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
						del(size);
				system("cls");
				cout << "Введите размер стека - ";
				cin >> size;
				cin.get();
				for (int i = 0; i < size; i++)
					add();
				cout << "Стек создан" << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 2:
			{
				system("cls");
				if (Head)
				{
					add_new();
					++size;
					cout << "Элемент добавлен" << endl;
				}
				else
					cout << "Стек пуст, невозможно произвести данную операцию." << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 3:
			{
				system("cls");
				if (Head)
				{
					del(size);
					--size;
					cout << "Элемент удалён" << endl;
				}
				else
					cout << "Стек пуст, невозможно произвести данную операцию." << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 4:
			{
				system("cls");
				if (Head)
					cout << Last->val.x << endl;
				else
					cout << "Стек пуст, невозможно произвести данную операцию." << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 5:
			{
				system("cls");
				if (Head)
				{
					while (size)
					{
						cout << Last->val.x << endl;
						del(size);
						--size;
					}
				}
				else
					cout << "Стек пуст, невозможно произвести данную операцию." << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			case 6:
			{
				system("cls");
				if (Head)
				{
					while (size)
					{
						del(size);
						--size;
					}
					cout << "Стек очищен" << endl;
				}
				else
					cout << "Стек пуст, невозможно произвести данную операцию." << endl;
				cout << "Нажмите Enter, чтобы перейти в меню" << endl;
				cin.get();
				break;
			}
			default:
			{
				system("cls");
				if (Head)
					while (size)
					{
						del(size);
						--size;
					}
				return 0;
				break;
			}
		}
	}
	return 0;
}