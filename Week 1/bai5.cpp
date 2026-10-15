#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Nhap N: ";
    cin >> n;

    double *a = new double[n];
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
        sum = sum + a[i];
    }

    double avg = sum / n;
    cout << "Average: " << avg << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= avg)
            cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;
    return 0;
}
// Do phuc tap: O(N); O(1)