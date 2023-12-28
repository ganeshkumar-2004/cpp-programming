#include <iostream>
#include <stack>
using namespace std;
stack<int>s;
int minElement;
void push(int x)
{
    if (s.size() == 0)
    {
        s.push(x);
        minElement = x;
    }
    else
    {
        if (x > minElement)
            s.push(x);
        else if (x <= minElement)
            s.push(2 * x - minElement);
            minElement = x;
    }
}
int pop()
{
    if (s.size() == 0)
        return -1;
    else if (s.size() >= minElement)
        s.pop();
    else if (s.top() < minElement)
        minElement = 2 * minElement - s.top();
        s.pop();
}
int top()
{
    if (s.top() == 0)
        return -1;
    if (s.top() >= minElement)
        return s.top();
    else if (s.top() < minElement)
        return minElement;
}
int getmin()
{
    if (s.size() == 0)
        return -1;
    return minElement; 
}

int main()
{
    push(10);
    push(13);
    push(12);
    push(4);
    push(20);
    push(52);
    int MIN = getmin();
    cout << "the minmum element of the stack : " << MIN<<endl;
    int topele = top();
    cout << "the top element of the stack : " << topele<<endl;
    pop();
    cout << "the top element of the stack : " << topele<<endl;
        

    return 0;
}
