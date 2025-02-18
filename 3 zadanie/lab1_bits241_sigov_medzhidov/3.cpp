#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int main()
{
    int n, y = 1;
    cin >> n;

    for (int i = n % 2; i <= n; ++i)
    {
        y *= i;
    }

    cout << y << endl;
}
