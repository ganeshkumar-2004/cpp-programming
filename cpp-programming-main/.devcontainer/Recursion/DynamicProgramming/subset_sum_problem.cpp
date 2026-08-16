#include <iostream>
using namespace std;
bool Is_subsetSum(int set[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
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
                t[i][j] = t[i-1][j - set[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}
int main()
{
    int n;
    cout << "enter the size of subset: "
         << " ";
    cin >> n;
    int set[n];
    cout << " Enter the element of the subset: " << " ";
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    int sum;
    cout << "Enter the sum thet subset you want find: " << " ";
    cin >> sum;
    if (Is_subsetSum(set, sum, n))
    {
        cout << "There is a subset with the given sum." << endl;
    }
    else
    {
        cout << "There is no subset with the given sum." << endl;
    }

    return 0;
}