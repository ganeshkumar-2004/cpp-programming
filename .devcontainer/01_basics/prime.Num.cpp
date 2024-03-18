#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, i = 2, s;
    s =(int) sqrt(n);
    cout << "Enter a number : ";
    cin >> n;
    for (i; i <= s; i++)
    {
        if (n % i == 0)
            break;
        i++;
    }
    if (i == s + 1)
        cout << "The number is prime " << endl;
    else
        cout << "The number is Nonprime " << endl;
    return 0;
}
