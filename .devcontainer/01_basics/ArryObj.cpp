#include <iostream>
using namespace std;
class Employee
{
    char name[30];
    float age;

public:
    void setData(void);
    void getData(void);
};

void Employee::setData(void)
{
    cout << " Enter Your Name : ";
    cin >> name;
    cout << " Enter your Age: ";
    cin >> age;
}
void Employee::getData(void)
{
    cout << " Name :" << name << endl;
    cout << " Age :" << age << endl;
}
const int size = 5;
int main()
{
    Employee manager[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"\n details of managers :"<<i+1<<endl;
        manager[i].setData();
    }
     cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<"\n Manager :  "<<i+1<<endl;
        manager[i].getData();
    }
        
    
    return 0;
}