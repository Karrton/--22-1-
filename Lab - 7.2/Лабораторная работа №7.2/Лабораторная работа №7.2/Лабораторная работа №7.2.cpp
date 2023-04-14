#include <iostream>
using namespace std;
void square()
{	
	int ax, ay, bx, by, cx, cy;
	cout << "Введите три координаты точек через пробел, чтобы вычислить площадь треугольника - ";
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	int p1_x = bx - ax;
	int p2_x = bx - cx;
	int p3_x = cx - ax;
	int p1_y = by - ay;
	int p2_y = by - cy;
	int p3_y = cy - ay;
	double p1 = sqrt(p1_x * p1_x + p1_y * p1_y);
	double p2 = sqrt(p2_x * p2_x + p2_y * p2_y);
	double p3 = sqrt(p3_x * p3_x + p3_y * p3_y);
	double p = (p1 + p2 + p3) / 2;
	cout << "Площадь заданного треугольника равна - " << sqrt(p * (p - p1) * (p - p2) * (p - p3)) << endl;
	return;
}
float square1(int k, ...)
{
	int *p = &k;
	float length1 = sqrt(*(p + 2) * *(p + 2) + *(p + 4) * *(p + 4));
	float length2 = sqrt(*(p + 6) * *(p + 6) + *(p + 8) * *(p + 8));
	float length3 = sqrt(*(p + 10) * *(p + 10) + *(p + 12) * *(p + 12));
	float buff = (length1 + length2 + length3) / 2;
	return (sqrt(buff * (buff - length1) * (buff - length2) * (buff - length3)));
}
int point_vector(int arr_x[], int arr_y[], int arr_point_x[], int arr_point_y[], int n)
{
	int sign = 1;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			arr_x[i] = arr_point_x[0] - arr_point_x[i];
			arr_y[i] = arr_point_y[0] - arr_point_y[i];
		}
		else
		{
			arr_x[i] = arr_point_x[i] - arr_point_x[i + 1];
			arr_y[i] = arr_point_y[i] - arr_point_y[i + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			sign *= arr_x[i] * arr_y[0] - arr_y[i] * arr_x[0];
		else
			sign *= arr_x[i] * arr_y[i + 1] - arr_y[i] * arr_x[i + 1];
	}
	return sign;
}
int main()
{	
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество точек многоугольника - ";
	int n = 0;
	cin >> n;
	int* arr_point_x = new int[n];
	int* arr_point_y = new int[n];
	int* arr_x = new int[n];
	int* arr_y = new int[n];
	float max = 0;
	int i_buff = 0;
	int j_buff = 0;
	int buff1 = 0;
	int buff2 = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << "-ую точку многоугольника (координаты через пробел) - ";
		cin >> arr_point_y[i] >> arr_point_x[i];
	}
	if (point_vector(arr_x, arr_y, arr_point_x, arr_point_y, n) < 0)
	{
		cout << "Заданный координатами многоугольник не выпуклый" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{	
				int e = arr_point_x[i] - arr_point_x[j];
				int r = arr_point_y[i] - arr_point_y[j];
				double length = sqrt(e * e + r * r);
				if (length > max)
				{
					max = length;
					i_buff = i;
					j_buff = j;
					buff1 = e;
					buff2 = r;
				}
		}
	if (i_buff == n - 1)
	{
		unsigned int p_x1 = arr_point_x[i_buff] - arr_point_x[0];
		unsigned int p_y1 = arr_point_y[i_buff] - arr_point_y[0];
		unsigned int p_x2 = arr_point_x[0] - arr_point_x[j_buff];
		unsigned int p_y2 = arr_point_y[0] - arr_point_y[j_buff];
		max = square1(6, p_x1, p_y1, p_x2, p_y2, buff1, buff2);
	}
	else
	{
		unsigned int p_x1 = arr_point_x[i_buff] - arr_point_x[i_buff + 1];
		unsigned int p_y1 = arr_point_y[i_buff] - arr_point_y[i_buff + 1];
		unsigned int p_x2 = arr_point_x[i_buff + 1] - arr_point_x[j_buff];
		unsigned int p_y2 = arr_point_y[i_buff + 1] - arr_point_y[j_buff];
		max = square1(6, p_x1, p_y1, p_x2, p_y2, buff1, buff2);
	}
	cout << "Площадь треугольника с наибольшей диагональю равна - " << max << endl;
	square();
	return 0;
}
