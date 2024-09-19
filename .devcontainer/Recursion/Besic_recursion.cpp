#include <iostream>
using namespace std;
int print(int n)
{
    if (n == 0)
        return 1;
    print(n - 1);
    std ::cout << n << " ";
}

int main()
{
    int n;
    cout<<"Enter the number from that you want to find till"<<endl;
    cin >> n;
    print(n);
    return 0;
}