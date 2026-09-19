#include <iostream>
#define STACK_UNDERFLOW 0
#define STACK_OVERFLOW 1
using namespace std;

class Stack
{
private:
    int capacity;
    int top;
    int *ptr;

public:
    Stack(int);
    void push(int);
    int peek();
    void pop();
    // bool isOverflow();
    bool isFull();
    bool isEmpty();
    // bool isUnderflow();
    void display();
    ~Stack();
};

Stack::Stack(int cap)
{
    capacity = cap;
    top = -1;
    ptr = new int[cap];
}

bool Stack::isFull()
{
    return (top + 1) == capacity;
}

bool Stack::isEmpty()
{
    return top == -1;
}

void Stack::push(int data)
{
    if (!isFull())
    {
        top++;
        ptr[top] = data;
    }
    else
    {
        throw STACK_OVERFLOW;
    }
}

int Stack::peek()
{
    if (isEmpty())
    {
        throw STACK_UNDERFLOW;
    }
    return ptr[top];
}

void Stack::pop()
{
    if (isEmpty())
    {
        throw STACK_UNDERFLOW;
    }
    top--;
}
void Stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << ptr[i] << " ";
    }
}
Stack::~Stack()
{
    delete[] ptr;
}
int main()
{
    Stack s(5);
    s.push(5);
    s.push(6);
    s.push(9);
    s.push(4);
    s.display();
    cout << endl<<s.peek();;
    
    s.pop();
    cout << endl;
    s.display();
    cout << endl<< s.peek();
   

    return 0;
}