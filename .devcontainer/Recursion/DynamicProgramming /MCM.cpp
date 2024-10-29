#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int static t[10001][1001];
int solve(int arr[], int i, int j)
{
    int mn = INT_MAX;
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    else
    {
        for (int k = i; k <= (j-1); k++)
        {
            int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            if (tempAns < mn)
            {
                mn = tempAns;
                t[i][j] = mn;
            }
        }
    }
    return t[i][j];
}
int main()
{
    memset(t, -1, sizeof(t));
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<solve(arr,1,n-1);
    return 0;
}
