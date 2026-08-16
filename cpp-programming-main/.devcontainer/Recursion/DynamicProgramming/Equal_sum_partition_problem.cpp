#include <iostream>
using namespace std;
bool Is_subsetSum(int set[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sum; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            else if (j == 0)
            {
                t[i][j] = true;
            }
            else if (set[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - set[i - 1]] || t[i - 1][j];
            }
            else {
                t[i][j]=t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

bool Equal_sum(int set[],  int n)
{
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum +=set[i];
    }
    if (totalsum % 2 != 0)
    {
        return false;
    }
    else
    {
        return Is_subsetSum(set, (totalsum) / 2, n);
    }
}
int main()
{
    int n, sum;
    cout << "Enter the size of set: " << " ";
    cin >> n;
    int set[n];
    cout << "Enter the element of the set: " << " ";
    for (int i = 0; i < n; i++) 
    {
        cin >> set[i];
    }
    cout << "Enter the sum of the subset: " << " ";
    cin >> sum;
    if (Equal_sum(set,n))
    {
        cout << "Yes, the given set can be divided into two eqaul sum partition of subset; " << endl;
    }
    else
    {
        cout << "NO, the given set can't be divided into two eqaul sum partition of subset " << endl;
    }

    return 0;
}