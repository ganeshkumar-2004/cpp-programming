#include <iostream>
using namespace std;
int Knapsack(int w, int n, int wt[], int val[])
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (wt[i - 1]<=j)
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
        
    }
    return t[n][w];
}
    int main()
    {
        int n;
        cout << "Enter the size of array: " << endl;
        cin >> n;
        int w;
        cout << " Enter the waight of the knapsack :" << endl;
        cin >> w;
        int wt[n];
        cout << " Enter the item into the knapsack: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        int val[n];
        cout << " Enter the value of item into the knapsack: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        cout << "The maximum profit of the knapsack: " << Knapsack(w, n, wt, val)<<endl;;

        return 0;
    }