// Program to print 1 to n 

#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }

    print(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cout << "Enter the number from that you want to find till" << endl;
    cin >> n;
    print(n);
    return 0;
}

// program to print n to 1 
// #include <iostream>
// using namespace std;
// void print(int n)
// {
//     if (n == 1)
//     {
//         cout << n << " ";
//         return;
//     }
//     cout << n << " ";
//     print(n - 1);
// }

// int main()
// {
//     int n;
//     cout << "Enter the number till that you want to find till" << endl;
//     cin >> n;
//     print(n);
//     return 0;
// }