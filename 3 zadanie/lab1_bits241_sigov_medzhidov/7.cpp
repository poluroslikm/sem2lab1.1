#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int n, res = 0, zn;

    cout << "¬ведите значение n: ";
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        zn = pow(i, 3) - 3 * i * pow(n, 2) + n;
        if (zn % 3 == 0 && zn % 2 != 0)
        {
            res += zn;
        }
    }
}
