#include <iostream>
using namespace std;
int knapsack(int w, int n, int wt[], int val[])
{
    if (w == 0 || n == 0)
        return 0;
    else if (wt[n - 1] <= w)
        return max(wt[n - 1] + knapsack(w - wt[n - 1], n - 1, wt, val), knapsack(w, n - 1, wt, val));
    else
        return knapsack(w, n - 1, wt, val);
    
}
int main()
{
    int n;
    cout << "Enter the size of array :" << endl;
    cin >> n;
    int w;
    cout << "Enter the capacity of knapsack :" << endl;
    cin >> w;
    int wt[n];
    cout << "Enter the weight of each item : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    int val[n];
    cout << "Enter the value of each item : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int maxProfit = knapsack(w, n, wt, val);
    cout<<"Maximum profit of the kanapsack problem "<<maxProfit<<endl;
    return 0;
}