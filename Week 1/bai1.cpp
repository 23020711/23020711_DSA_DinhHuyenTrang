#include <iostream>

using namespace std;

int sumArray(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << sumArray(a, n) << endl;

    delete[] a;
    return 0;
}
//Do phuc tap: 0(N); O(1)