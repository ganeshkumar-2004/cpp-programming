#include <iostream>
using namespace std;
class FirstNum;
class SecondNum
{
    int value1;

public:
    void inData(int a) { value1 = a; }
    void sowData(void)
    {
        cout << "The value of second num :" << value1 << endl;
    }
    friend void Exchange(SecondNum &, FirstNum &);
};
class FirstNum
{
    int value2;

public:
    void inData(int b) { value2 = b; }
    void sowData(void)
    {
        cout << " The value of first Num : " << value2 << endl;
    }
    friend void Exchange(SecondNum &, FirstNum &);
};
void Exchange(SecondNum &A, FirstNum &B)
{
    int temp = A.value1;
    A.value1 = B.value2;
    B.value2 = temp;
}

int main()
{
    SecondNum second;
    FirstNum first;
    second.inData(100);
    first.inData(300);
    cout << " the value before exchange : " << endl;
    second.sowData();
    first.sowData();
    cout << " the value After exchange : " << endl;
    Exchange(second, first);
    second.sowData();
    first.sowData();
    return 0;
}
