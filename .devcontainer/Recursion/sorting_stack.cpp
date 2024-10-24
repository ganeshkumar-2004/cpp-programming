#include <iostream>
#include <stack>
using namespace std;
void insert(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
        s.push(temp);
    else
    {
        int val = s.top();
        s.pop();
        insert(s, temp);
        s.push(val);
    }
}
void sort(stack<int> &s)
{
    if (s.size() == 0)
    {
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        sort(s);
        insert(s, temp);
    }
}
int main()
{
    int n;
    cout << "Enter the size of stack: " << " ";
    cin >> n;
    stack<int> s;
    cout << "Enter the element of stack: " << " ";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        s.push(element);
    }
    sort(s);
    cout << " Your Sorted stack is : " << " ";
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}