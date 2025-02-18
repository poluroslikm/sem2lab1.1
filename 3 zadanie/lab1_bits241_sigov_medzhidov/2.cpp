#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

void main()
{
	float a, min = 1000000, max = -1000000, res;
	int i = 0;
	while (i < 100)
	{
		cin >> a;
		cout << "a" << i + 1 << "=" << a << "\n";
		if (a < min) min = a;
		if (a > max) max = a;
		i++;
	}
	res = max - min;
	cout << "результат = " << res;
}
