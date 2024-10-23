#include <iostream>
#include <vector>
using namespace std;
void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    else
    {
        int val = v[v.size() - 1];
        v.pop_back();
        insert(v, temp);
        v.push_back(val);
    }
}

void sort(vector<int> &v)
{
    if (v.size() == 0)
        return;
    else
    {
        int m = v[v.size() - 1];
        v.pop_back();
        sort(v);
        insert(v, m);
    }
}
int main()
{
    int n;
    cout << "Enter the value of n: " << " ";
    cin >> n;
    vector<int> v;
    cout << "Enter the value of the vector element: " << " ";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    sort(v);
    cout<<"The sorted array : "<<" ";
    for (int i = 0; i < n; i++)
    {
        cout<<v[i];
        cout<<" ";
    }
    
}