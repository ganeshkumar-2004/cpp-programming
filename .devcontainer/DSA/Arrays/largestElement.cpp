#include <iostream>
#include <climits>
using namespace std;
//time complexity of this program is T(n)

int largest_Element(int arr[], int n)
{
    int maxelement = INT32_MIN;
    for (int i = 0; i <= n; i++)
    {
        if (maxelement < arr[i])
            maxelement = arr[i];
    }
    return maxelement;
}
int main()
{
    int arr[] = {3, 35, 6, 69, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << largest_Element(arr, n) << endl;
    return 0;
}
