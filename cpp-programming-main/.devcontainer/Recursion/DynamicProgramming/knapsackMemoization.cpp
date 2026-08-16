#include <iostream>
#include <cstring>
using namespace std;
int knapsack(int w, int n, int wt[], int val[])
{
    int t[n + 1][w + 1];
    memset(t, -1, sizeof(t));
    if (n == 0 || w == 0)
        return 0;
    if (t[n][w] != -1)
        return t[n][w];
    else if (wt[n - 1] <=w)
        return t[n][w]=max(val[n-1]+knapsack(w-wt[n-1],n-1,wt,val),knapsack(w,n-1,wt,val));
    else 
        return t[n][w]=knapsack(w,n-1,wt,val);
}
int main(){
    int n;
    cout<<"Enter the size of arry : "<<endl;
    cin>>n;
    int w;
    cout<<"Enter the size of knapsack  : "<<endl;
    cin>>w;
    int wt[n];
    cout<<"Enter the weight of value : "<<" ";
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    }
    int val[n];
    cout<<"Enter the value of each item :"<<" ";
    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    }
    cout<<"The maximum ouput of the knapsack problem is : "<<knapsack(w,n,wt,val)<<endl;

    return 0;
    
}
