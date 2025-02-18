#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else return n;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    double res = 0;

    for (int k = 1; k <= 10; ++k)
    {
        double res2 = 0;
        for (int n = 1; n <= k; ++n)
        {
            res2 += sin(k * n);
        }
        res2 /= factorial(k);

        res += res2;
    }

    cout << "Результат выполнения программы: " << res;
}
