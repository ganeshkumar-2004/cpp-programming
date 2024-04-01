#include <iostream>
using namespace std;
int main()
{
    int i, n;
    int num[50], *ptr;
    cout << "Enter the size of array" << endl;
    cin >> n;
    cout << "Enter the element of array one by one : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    ptr = num;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if (*ptr % 2 == 0)
            sum+= *ptr;
            ptr++;
    }
    cout<< " The sum of the even number is : "<<sum;
    return 0; 
}