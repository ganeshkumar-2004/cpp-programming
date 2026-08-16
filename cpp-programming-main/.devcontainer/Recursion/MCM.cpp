#include <iostream>
#include <climits>
using namespace std;
int solve(int arr[], int i, int j)
{
    int mn =INT_MAX;
    if (i >= j)
    {
        return 0;
    }
    else
    {
        for (int k = i; k <= (j - 1); k++)
        {
            int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            if (tempAns < mn)
            {
                mn = tempAns;
            }
        }
    }
    return mn;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the element of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Minimal cost of matix chain multiplocation is : " << solve(arr, 1, n - 1)<<endl;

    return 0;
}
