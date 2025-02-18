#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    double res = 0;

    cout << "Введите значение n: ";
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            res += 1 / (i + 2 * j);
        }
    }

    cout << "Результат выполнения программы: " << res;
}
