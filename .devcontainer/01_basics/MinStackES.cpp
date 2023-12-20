#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
stack<int> ss;

void push(int n)
{
    s.push(n);
    if (ss.size() == 0 || ss.top() >= n)
        ss.push(n);
}

int pop()
{
    if (s.size() == 0)
        return -1;
    int ans = s.top();
    if (s.top() == ans)
        ss.pop();

    return ans;
}

int getMin()
{
    if (ss.size() == 0)
        return -1;
    return ss.top();
}

int main()
{
    push(10);
    push(16);
    push(16);
    push(18);
    push(7);
    push(12);
    int MIN = getMin();
    cout << "Minmum element into the stack : " << MIN << endl;
    int ANS = pop();
    cout << "The poped element from the stack : " << ANS;

    return 0;
}