#include <iostream>
#include <locale.h>
#include <cmath>
#define N 4

using namespace std;

void filarr(int arr[N][N])
{
    int count = 1;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = i - 1; j < N-i+1; ++j)
        {
            arr[i - 1][j] = count;
            ++count;
        }
        
        for (int j = i; j < N - i; ++j)
        {
            arr[j][N - i] = count;
            ++count;
        }

        for (int j = N - i; j >= i - 1; --j)
        {
            arr[N - i][j] = count;
            ++count;
        }

        for (int j = N - 1 - i; j >= i; --j)
        {
            arr[j][i - 1] = count;
            ++count;
        }
    }
}

void show(int arr[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%2d ", arr[i][j]);
        }
        cout << '\n';
    }
}

int findopr(int arr[N][N], int n)
{
    if (n == 3)
    {
        return ((arr[0][0] * arr[1][1] * arr[2][2]) + (arr[0][1] * arr[1][2] * arr[2][1]) + (arr[1][0] * arr[2][1] * arr[0][2]) \
            - (arr[0][2] * arr[1][1] * arr[2][0]) - (arr[0][0] * arr[2][1] * arr[1][2]) - (arr[2][2] * arr[1][0] * arr[0][1]));
    }
    return (pow(-1, n) * findopr(arr, n - 1) + pow(-1, n + 1) * findopr(arr, n - 1) + pow(-1, n + 2) * findopr(arr, n - 1))
}

int main()
{
    int arr[N][N];

    filarr(arr);
    show(arr);
}
