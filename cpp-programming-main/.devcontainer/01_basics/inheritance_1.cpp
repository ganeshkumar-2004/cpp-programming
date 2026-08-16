#include <iostream>
using namespace std;
class Student
{
protected:
    int Roll_NUM;

public:
    Student() {}
    Student(int rollNum)
    {
        Roll_NUM = rollNum;
    }
    void get_rollNum(void)
    {
        cout << "The roll Number of The studant : " << Roll_NUM << endl;
    }
};
class Test : public Student
{
protected:
    float maths, physics;

public:
    Test() {}
    Test(int a, float b, float c) : Student(a)
    {
        maths = c;
        physics = b;
    }
    void getMarks(void)
    {
        cout << "Marks in physics : " << physics << endl;
        cout << "Marks in maths : " << maths << endl;
    }
};
class Result : public Test
{
    float total=0.0;

public:
    Result(int a, float b,float c) : Test(a, b,c) {}

    void Display(void)
    {
        total = maths + physics;

        get_rollNum();
        getMarks();
        cout << "The total number of all marks : " << total << endl;
    }
};
int main()
{
    Result res(100, 90.5, 98.6);
    res.Display();
    return 0;
}
