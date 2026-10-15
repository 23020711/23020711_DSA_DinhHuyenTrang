#include <iostream>

using namespace std;

void deleteElement(int *a, int *n, int k)
{
    for (int i = k; i < *n - 1; i++)
        a[i] = a[i + 1];
    *n = *n - 1;
}

void insertElement(int *a, int *n, int y, int m)
{
    for (int i = *n; i > m; i--)
        a[i] = a[i - 1];
    a[m] = y;
    *n = *n + 1;
}

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Nhap N: ";
    cin >> n;

    int *a = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    int k;
    cin >> k;
    if (k < 0 || k >= n)
        cout << "Invalid" << endl;
    else
    {
        deleteElement(a, &n, k);
        print(a, n);
    }

    int y, m;
    cin >> y;
    cin >> m;
    if (m < 0 || m > n)
        cout << "Invalid" << endl;
    else
    {
        insertElement(a, &n, y, m);
        print(a, n);
    }
    delete[] a;
    return 0;
}
// Do phuc tap: O(N); O(1)