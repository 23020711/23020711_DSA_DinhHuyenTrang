#include <iostream>

using namespace std;

long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result = result * i;
    return result;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n < 0)
        cout << "n >= 0" << endl;
    else if (n > 20)
        cout << "n is too large" << endl;
    else
        cout << factorial(n) << endl;

    return 0;
}
// Do phuc tap: O(N); O(1)