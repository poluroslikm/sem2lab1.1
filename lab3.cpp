#include <iostream>
#include <locale.h>
#include <cmath>
#include <vector>
#define N 4

using namespace std;

void filarr(vector <vector <int>> &arr)
{
    int count = 1;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = i - 1; j < N - i + 1; ++j)
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

void show(vector <vector <int>> arr)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[i][j] < 10) cout << " ";
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

int opr(vector <vector <int>> arr)
{
    return (arr[0][0] * arr[1][1] * arr[2][2]) + (arr[0][1] * arr[1][2] * arr[2][0]) + (arr[0][2] * arr[1][0] * arr[2][1]) \
        - (arr[0][2] * arr[1][1] * arr[2][0]) - (arr[0][0] * arr[1][2] * arr[2][1]) - (arr[0][1] * arr[1][0] * arr[2][2]);
}

void transpl(vector <vector <int>>& arr) {
    int temp;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // Меняем местами элементы arr[i][j] и arr[j][i]
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

//void transpl(int (&arr)[N][N])
//{
//    int arr2[N][N] = { { arr[0][0], arr[1][0], arr[2][0], arr[3][0] }, { arr[0][1], arr[1][1], arr[2][1], arr[3][1] }, \
//    { arr[0][2], arr[1][2], arr[2][2], arr[3][2] }, { arr[0][3], arr[1][3], arr[2][3], arr[3][3] } };
//}

int findopr(vector <vector <int>> arr)
{
    int count1 = 0;
    int iter = 0;
    int n = 0;
    vector <vector <int>> arr2(N, vector <int>(N));
    for (int iter = 0; iter < 4; ++iter)
    {
        for (int k = 0; k < 3; ++k)
        {
            int count2 = 0;
            for (int m = 0; m < 4; ++m)
            {
                if (m == iter)
                {
                    ++count2;
                    continue;
                }
                arr2[k][m - count2] = arr[k + 1][m];
            }
        }
        /*cout << endl;
        show(arr2);
        cout << endl;*/
        int num = opr(arr2);
        count1 += pow(-1, n) * arr[0][iter] * num;
        // cout << num << endl;
        ++n;
    }

    return count1;
    /*return (pow(-1, n) * arr[0][0] * \
        ((arr[1][1] * arr[2][2] * arr[3][3]) + (arr[1][2] * arr[2][3] * arr[3][1]) + (arr[1][3] * arr[2][1] * arr[3][2]) \
            - (arr[1][3] * arr[2][2] * arr[3][1]) - (arr[1][1] * arr[2][3] * arr[3][2]) - (arr[1][2] * arr[2][1] * arr[3][3])) \
        + pow(-1, n + 1) * arr[0][1] * \
        ((arr[1][1] * arr[2][2] * arr[3][3]) + (arr[1][2] * arr[2][3] * arr[3][0]) + (arr[1][3] * arr[2][0] * arr[3][2]) \
            - (arr[1][3] * arr[2][2] * arr[3][0]) - (arr[1][0] * arr[2][3] * arr[3][2]) - (arr[1][2] * arr[2][0] * arr[3][3])) \
        + pow(-1, n + 2) * arr[0][2] * \
        ((arr[1][0] * arr[2][1] * arr[3][3]) + (arr[1][1] * arr[2][3] * arr[3][0]) + (arr[1][3] * arr[2][0] * arr[3][1]) \
            - (arr[1][3] * arr[2][1] * arr[3][0]) - (arr[1][0] * arr[2][3] * arr[3][1]) - (arr[1][1] * arr[2][0] * arr[3][3])) \
        + pow(-1, n + 3) * arr[0][3] * \
        ((arr[1][0] * arr[2][1] * arr[3][2]) + (arr[1][1] * arr[2][2] * arr[3][0]) + (arr[1][2] * arr[2][0] * arr[3][1]) \
            - (arr[1][2] * arr[2][1] * arr[3][0]) - (arr[1][0] * arr[2][2] * arr[3][1]) - (arr[1][1] * arr[2][0] * arr[3][2])));*/
}


vector <vector <double>> obrmatr(vector <vector <int>> arr)
{
    vector <vector <int>> arr_copy(N, vector <int>(N));
    transpl(arr_copy);
    vector <vector <double>> new_arr(N, vector <double>(N));
    vector <vector <int>> um_arr(N, vector <int>(N));
    int det = findopr(arr);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int count1 = 0;
            for (int k = 0; k < 4; ++k)
            {
                int count2 = 0;
                if (k == i)
                {
                    ++count1;
                    continue;
                }
                for (int m = 0; m < 4; ++m)
                {
                    if (m == j)
                    {
                        ++count2;
                        continue;
                    }
                    um_arr[k - count1][m - count2] = arr[k][m];
                }
            }
            int num = opr(um_arr);
            /*cout << num << " " << det << endl;
            cout << endl;*/
            new_arr[i][j] = pow(-1, i + j + 2) * num / det;
            cout << endl;
            show(um_arr);
            cout << num;
            //cout << i + 1 << " " << j + 1 << endl;
            cout << endl;
        }
    }
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (new_arr[i][j] < 10) cout << " ";
            cout << new_arr[i][j] << " ";
        }
        cout << '\n';
    }

    return new_arr;
}

void umn_matr(vector <vector <int>> arr, vector <vector <double>> arr_obr)
{
    vector<vector<double>> res(N, vector<double>(N, 0));

    // Умножение матриц
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res[i][j] += arr[i][k] * arr_obr[k][j];
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (res[i][j] < 10) cout << " ";
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    vector <vector <int>> arr(N, vector <int> (N));

    filarr(arr);
    show(arr);

    //cout << findopr(arr);
    vector <vector <double>> arr2(N, vector <double>(N));
    arr2 = obrmatr(arr);
    //show(arr2);
    cout << endl;
    umn_matr(arr, arr2);
}
