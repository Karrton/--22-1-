#include <iostream>
using namespace std;
const int a = 10;
const int b = 10;
void fun(int arr[])
{	
	int q = 0;
	for (int i = 0; i < a; i++)
		if (arr[i] == 0)
			for (int j = a; j > 0; j--)
				if (arr[j] == 0)
					for (int k = i; k < j; k++)
						arr[k] = 0;	
	for (int i = 0; i < a; i++)
		if (arr[i] != 0)
		{
			arr[q] = arr[i];
			++q;
		}
	cout << "----------" << endl;
	cout << "Преобразованный одномерный массив - ";
	if (q == 0)
		cout << "преобразованный массив нулевой";
	for (int i = 0; i < q; i++)
		cout << arr[i] << " ";
	cout << endl;
	return;
}
void fun(int arr[a][b])
{	
	int q = 0;
	for (int i = 1; i < a; i += 2)
	{
		for (int j = 0; j < b; j++)
		{
			arr[q][j] = arr[i][j];
		}
		++q;
	}
	for (int i = 0; i < q; i++)
	{
		for (int j = 0; j < b; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
int main() 
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int arr[a];
	int arr_add[a][b];

	for (int i = 0; i < a; i++)
		arr[i] = rand() % 4;
	for (int i = 0; i < a; i++)
		cout << arr[i] << " ";
	cout << endl;
	fun(arr);
	cout << "----------" << endl;

	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			arr_add[i][j] = rand() % 10;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << arr_add[i][j] << " ";
		cout << endl;
	}
	cout << "----------" << endl;
	cout << "Массив из четных строк" << endl;
	cout << "----------" << endl;

	fun(arr_add);
}