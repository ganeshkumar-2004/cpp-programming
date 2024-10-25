#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.top();
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        solve(s, k - 1);
        s.push(temp);
    }
}

stack<int> Mid_delete(stack<int> s, int n)
{
    if (s.size() == 0)
    {
        return s;
    }
    else
    {
        int k = (s.size() / 2) + 1;
        solve(s, k);
    }
    return s;
}
int main()
{
    int n;
    cout << " Enter the size of stack: " << " ";
    cin >> n;
    stack<int> s;
    cout << " enter the element of the a stack: " << " ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.push(temp);
    }
    stack<int> st = Mid_delete(s, n);
    cout << "After deleting the mid element of the stack : " << " ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}