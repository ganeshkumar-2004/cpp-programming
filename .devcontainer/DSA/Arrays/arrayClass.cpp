#include<iostream>
#define ARRAY_UNDERFLOW 0
#define ARRAY_OVERFLOW 1 
#define INVALID_INDEX 2 
using namespace std;

class Array{
    private :
        int capacity ; 
        int last_index;
        int *ptr;
    public: 
        Array(int);
        bool is_empty();
        void append(int);//insert at last 
        void insert_specific_position(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get_element(int);
        int count( );
        ~Array();
        int find_element(int);
};


Array :: Array(int cap){
        if(cap<1)
            cap=10;
        capacity = cap;
        last_index = -1;
        ptr = new int[cap];
}
bool Array::isFull()
{
    return last_index+1 == capacity;
}

bool Array::is_empty(){
            return last_index == -1;
        }

void Array::append(int data){
    if(isFull())
        throw ARRAY_OVERFLOW;
    last_index++;
    ptr[last_index] = data;
}        
void Array::insert_specific_position(int index, int data)
{
    if(isFull())
        throw ARRAY_OVERFLOW;
    if(index < 0 || index>last_index + 1)
        throw INVALID_INDEX;
    for(int i = last_index; i>=index; i--){
        //shiftiong the data into the array
        ptr[i+1] = ptr[i];
    }
    ptr[index] = data;
    last_index++;
}
void Array::edit(int index , int data){
    if(index < 0 || index>last_index)
        throw INVALID_INDEX;
    ptr[index] = data;
}
void Array::del(int index){
    if(is_empty())
        throw ARRAY_UNDERFLOW;
    if(index < 0 || index>last_index)
        throw INVALID_INDEX;
    for(int i = index; i<last_index; i++)
        ptr[i] = ptr[i+1];
    last_index--;

}
int Array::get_element(int index){
    if(index < 0 || index>last_index)
        throw INVALID_INDEX;
    return ptr[index];
}
int Array::count(){
    return last_index + 1;
}
Array::~Array(){
    delete []ptr;
}
int Array::find_element(int data){
    for(int i = 0 ; i<= last_index; i++)
        if(ptr[i] == data)
            return i;
    return -1;
}

int main(){
    Array arr(5);
    arr.append(10);
    arr.append(20);
    arr.append(30);
    arr.append(40);
    arr.insert_specific_position(1,15);
    cout<<"total element : "<<arr.count()<<endl;
    arr.del(0);
    for(int i = 0 ; i<arr.count() ; i++){
        cout<<" "<<arr.get_element(i);
    }
    cout<<endl;
    return 0 ;
}