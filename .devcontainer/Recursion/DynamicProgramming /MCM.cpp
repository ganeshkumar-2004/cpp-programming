#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int static t[100][100];
int solve(int arr[], int i, int j)
{
    if (i == j)
        return 0;

    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    int mn = INT_MAX;

    for (int k = i; k <= (j - 1); k++)
    {
        int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        mn = min(mn, tempAns);
        t[i][j] = mn;
    }

    return t[i][j];
}
int main()
{
    memset(t, -1, sizeof(t));
    cout << "Enter the size of array which containing the dimentaion of matrices :  ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the dimentaion of matrices :  ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Minimum cost of matrix chain multiplication : " << solve(arr, 1, n - 1) << endl;
    return 0;
}
