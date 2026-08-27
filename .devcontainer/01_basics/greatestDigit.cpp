#include <iostream>
using namespace std;
int greatestdigit(int n)
{
    int mxdigit = n % 10;
    n = n / 10;
    while (n)
    {
        if (mxdigit < n % 10)
            mxdigit = n % 10;
        n = n / 10;
    }
    return mxdigit;
}
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    cout << "The largest digit of the number is the : " << greatestdigit(n);

    return 0;
}