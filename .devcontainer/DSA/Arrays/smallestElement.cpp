#include <iostream>
using namespace std;
int smallestElement(int arr[], int n)
{
    int smallestElement = arr[0];
    for (int i = 0; i <= n; i++)
    {
        if (smallestElement > arr[i])
            smallestElement = arr[i];
    }
    return smallestElement;
}
int main()
{
    int arr[] = {
        10,
        25,
        4,
        8,
        0,
        6,
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << smallestElement(arr, n);
    return 0;
}