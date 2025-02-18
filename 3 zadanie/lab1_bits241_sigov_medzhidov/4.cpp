#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int x, n;

    cout << "¬ведите число x: ";
    cin >> x;

    cout << "¬ведите число n: ";
    cin >> n;

    double res = 0;

    for (int k = 1; k <= n; ++k)
    {
        for (int m = k; m <= n; ++m)
        {
            res += (x + k) / m;
        }
    }

    cout << "–езультат выполнени€ программы: " << res;
}
