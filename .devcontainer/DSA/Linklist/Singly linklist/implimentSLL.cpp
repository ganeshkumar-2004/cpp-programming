#include<iostream> 
using namespace std;
struct node{
    int item ;
    node* next;
};

class SLL {
private: 
    node* start ;

public:
    SLL();
    void insert_at_start(int);
    void insert_at_end(int);
    void search(int);
    void insert_after(int, int);
    void delete_first();
    void delete_last();
    void delete_specific();
    ~SLL();
};

SLL:: SLL(){
    start = NULL;
}

void SLL:: insert_at_start(int data){
    node* newNode = new node; 
    newNode->item = data;
    if(start == NULL){
        start = newNode;
        newNode->next = NULL;
    }
    else{
        newNode->next = start;
        start = newNode;
    }

}




