#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int main()
{
	int n, j = 1;
	cin >> n;
	while (j <= n)
	{
		if (n % j == 0) cout << j << endl;
		++j;
	}

}