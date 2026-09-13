#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
    node *prev;
};
class DLL
{
private:
    node *start;

public:
    DLL();
    void insertStart(int);
    void insertLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteSpecific(node *);
    void Display()
    {

        node *current = start;
        while (current != NULL)
        {
            cout << current->item << " ";
            current = current->next;
        }
    }

    ~DLL();
};

DLL::DLL()
{
    start = nullptr;
}
void DLL::insertStart(int data)
{
    node *newNode = new node;
    newNode->prev = nullptr;
    newNode->item = data;
    if (start == nullptr)
    {
        start = newNode;
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
}
void DLL::insertLast(int data)
{
    node *newNode = new node;
    newNode->item = data;
    newNode->next = nullptr;
    if (start == nullptr)
    {
        start = newNode;
        newNode->prev = nullptr;
    }
    else
    {
        node *t;
        t = start;
        if (t->next == nullptr)
        {
            start->next = newNode;
            newNode->prev = start;
        }
        while (t->next != nullptr)
        {
            t = t->next;
        }
        t->next = newNode;
        newNode->prev = t;
    }
}

node *DLL::search(int data)
{
    node *t;
    t = start;
    while (t != nullptr)
    {
        if (t->item == data)
            return t;
        t = t->next;
    }
    return nullptr;
}
void DLL::insertAfter(node *temp, int data)
{
    if (temp != nullptr)
    {
        node *t;
        t = start;
        while (t != nullptr)
        {
            if (t == temp)
            {
                break;
            }
            t = t->next;
        }
        if (t == nullptr)
            cout << "specified node does not belong in this list" << endl;
        else
        {
            node *newNode = new node;
            newNode->item = data;
            newNode->next = t->next;
            if (t->next != nullptr)
            {
                t->next->prev = newNode;
            }
            t->next = newNode;
            newNode->prev = t;
        }
    }
}

void DLL::deleteFirst()
{
    if (start != nullptr)
    {
        node *t = start;
        if (start->next == nullptr)
        {
            delete start;
            start = nullptr;
        }
        else
        {
            start->next->prev = nullptr;
            start = t->next;
            delete t;
        }
    }
}

void DLL::deleteLast()
{
    if (start != nullptr)
    {
        node *t = start;
        if (t->next == nullptr)
        {
            delete start;
            start = nullptr;
        }
        else
        {
            while (t->next->next != nullptr)
            {
                t = t->next;
            }
            node *temp = t->next;
            t->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }
    }
}

void DLL::deleteSpecific(node *temp)
{
    if (temp != nullptr)
    {
        if (temp == start)
        {
            deleteFirst();
        }
        else if (temp->next == nullptr)
        {
            deleteLast();
        }
        else
        {
            node *n = start;
            while (n != nullptr)
            {
                if (n == temp)
                {
                    node *t = n;
                    n->next->prev = n->prev;
                    n->prev->next = n->next;
                    delete t;
                }
                n = n->next;
            }
        }
    }
}
DLL::~DLL()
{
    while (start != nullptr)
    {
        deleteFirst();
    }
}

int main()
{
    DLL D1;
    D1.insertStart(8);
    D1.insertStart(10);
    D1.insertStart(85);
    D1.insertStart(96);
    D1.insertLast(47);
    node *temp = D1.search(10);
    D1.insertAfter(temp, 18);
    D1.Display();
    D1.deleteFirst();
    D1.deleteLast();
    D1.deleteSpecific(temp);
    cout<<endl;
    D1.Display();
    
    return 0;
}