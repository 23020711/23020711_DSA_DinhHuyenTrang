#include <iostream>

using namespace std;

void reduceFraction(int *a, int *b)
{
    if (*b < 0)
    {
        *a = -*a;
        *b = -*b;
    }

    int x = *a, y = *b;
    if (x < 0)
        x = -x;
    while (y != 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }

    *a = *a / x;
    *b = *b / x;
}

int main()
{
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;

    if (b == 0)
    {
        cout << "b khac 0" << endl;
        return 0;
    }

    reduceFraction(&a, &b);
    cout << a << "/" << b << endl;

    return 0;
}
//Do phuc tap: O(log(min(a,b))); O(1)