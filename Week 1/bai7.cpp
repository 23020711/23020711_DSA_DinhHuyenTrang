#include <iostream>

using namespace std;

int sumArray(int a[][100], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += a[i][j];
    return sum;
}

void deleteRow(int a[][100], int *n, int m, int d)
{
    for (int i = d; i < *n - 1; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    *n = *n - 1;
}

void print(int a[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int a[100][100];
    int n, m;
    cout << "Nhap N, M: ";
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Sum of array: " << sumArray(a, n, m) << endl;

    int d;
    cout<<"Nhap d: ";
    cin >> d;
    if (d < 0 || d >= n)
        cout << "Invalid" << endl;
    else
    {
        deleteRow(a, &n, m, d);
        print(a, n, m);
    }

    return 0;
}
//Do phuc tap: O(NM); O(1)