#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};

class SLL
{
private:
    node *start;

public:
    SLL();
    void insert_at_start(int);
    void insert_at_end(int);
    void search(int);
    void insert_after(int, int);
    void delete_first();
    void delete_last();
    void delete_specific(int);
    void Display();
    ~SLL();
};

SLL::SLL()
{
    start = NULL;
}

void SLL::insert_at_start(int data)
{
    node *newNode = new node;
    newNode->item = data;
    if (start == NULL)
    {
        start = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = start;
        start = newNode;
    }
}
void SLL::insert_at_end(int data)
{
    node *newNode = new node;
    newNode->item = data;
    newNode->next = NULL;
    node *current = start;
    if (current == NULL)
    {
        start = newNode;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }
}

void SLL::search(int data)
{
    node *current = start;
    while (current != NULL)
    {
        if (current->item == data)
            cout << current->item << " Present In the list" << endl;
        current = current->next;
    }
}

void SLL::insert_after(int index, int data)
{
    if (start == NULL)
    {
        return;
    }
    node *newNode = new node;
    int count = 0;
    newNode->item = data;
    node *current = start;

    while (current != NULL)
    {
        if (count == index)
        {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        count++;
        current = current->next;
    }
}

void SLL::delete_first()
{
    if (start == NULL)
    {
        return;
    }
    node *temp = start;
    start = start->next;
    delete temp;
}
void SLL::delete_last()
{
    if (start == NULL)
    {
        return;
    }
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
        return;
    }
    node *current = start;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    node *temp = current->next;
    current->next = NULL;
    delete temp;
}
void SLL::delete_specific(int index)
{
    if (start == NULL)
    {
        return;
    }
    if (index == 0)
    {
        delete_first();
        return;
    }
    node *previous = NULL;
    node *current = start;
    int count = 0;
    while (count < index && current != NULL)
    {
        previous = current;
        current = current->next;
        count++;
    }
    if (current == NULL)
    {
        return;
    }

    previous->next = current->next;
    delete current;
}
void SLL::Display()
{
    node *current = start;
    while (current != NULL)
    {
        cout << current->item << " ";
        current = current->next;
    }
}
SLL::~SLL()
{
    node *current;
    while (start != NULL)
    {
        current = start;
        start = start->next;
        delete current;
    }
}

int main()
{
    SLL s1;
    s1.insert_at_start(5);
    s1.insert_at_start(9);
    s1.insert_at_start(13);
    s1.insert_after(2, 14);
    s1.insert_at_end(28);
    cout<<"Before delete operation: "<<endl;
    s1.Display();
    s1.delete_first();
    s1.delete_last();
    s1.delete_specific(2);
    cout<<"\n";
    cout<<"After delete operation: "<<endl;
    s1.Display();
    return 0;
}