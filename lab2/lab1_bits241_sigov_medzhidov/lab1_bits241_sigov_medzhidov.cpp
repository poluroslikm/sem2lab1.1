#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

void zad1()
{
	double a, b;
	int n, max= -2147483648, sum=0;
	float mid;
	cout << "Введите размер массива: ";
	cin >> n;
	int* arr{ new int[n] };
	for (int i=0; i < n; i++)
	{
		cout << i+1 << "-й элемент массива: ";
		cin >> arr[i];
		if (arr[i] > max)
			max = arr[i];
		sum += arr[i];
	}
	cout << "Максимальный элемент: " << max;
	mid = sum / n;
	cout << "\nСреднее арифметическое: " << mid;
	cout << "\nМассив в обратном порядке: ";
	for (int i = n-1; i >= 0; i--)
		cout << arr[i] << " ";
}

void zad2()
{
	int arr[4][6];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << i+1<< "-я строка " << j+1<< "-ый столбец: ";
			cin >> arr[i][j];
		}
	}
	int n, arr2[4];
	cout << "Введите число больше которого будут элементы массива: ";
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		arr2[i] = 0;
		for (int j = 0; j < 6; j++)
		{
			if (arr[i][j] > n)
				arr2[i]++;
		}
	}
	cout << "Второй массив: ";
	for (int i = 0; i < 4; i++)
	{
		cout << arr2[i] << " ";
	}
}
void zad3()
{
}

int main()
{
	setlocale(LC_ALL, "RUS");
	char sw;
	cout << "Выберите задание (1, 2 или 3) \n";
	cin >> sw;
	switch (sw)
	{
	case '1': zad1();
		break;
	case '2': zad2();
		break;
	case '3': zad3();
		break;
	default: cout << "Неизвестная операция";
	}

}
