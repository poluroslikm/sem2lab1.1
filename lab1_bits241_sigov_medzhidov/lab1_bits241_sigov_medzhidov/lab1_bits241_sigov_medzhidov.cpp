#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

void zad1()
{
	double a, b;

	cout << "Введите первое значение: ";
	cin >> a;

	cout << "Введите второе значение: ";
	cin >> b;

	double res = pow(sin(a + pow(b, 3)), 2) * sqrt(exp(pow(a, 2) - 9.4) / pow(a + b, 3));

	cout << "Результат выполнения функции zad1 для значений " << a << " и " << b << ": " << res << '\n';
}

double super_pow(double value, unsigned int spow)
{
	int res = value;
	for (int i = 0; i < spow; ++i)
	{
		res *= value;
	}
	return res;
}

void zad2()
{
	double x, x0=1, x1, f = 0, n = 2, e = 0.001;

	cout << "Введите значение для x: ";
	cin >> x;
	
	if (abs(x) >= 1)
	{
		cout << "Ошибка! x больше или равен единице \n";
		return;
	}

	x1 = -1 * x;
	++n;
	f += x0 + x1;
	while (abs(x0 - x1) <= e)
	{

		x0 = super_pow(-1, n - 1) * super_pow(x, n - 1);
		++n;
		x1 = super_pow(-1, n - 1) * super_pow(x, n - 1);
		++n;
		f += x0 + x1;
	}

	cout << f << "\n";
}

int main()
{
	setlocale(LC_ALL, "RUS");

	// zad1();
	// zad2();

}
