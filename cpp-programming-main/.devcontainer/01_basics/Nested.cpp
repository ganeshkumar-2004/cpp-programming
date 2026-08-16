#include <iostream>
using namespace std;
class Set
{
    int m, n;

public:
    void input(void);
    void display(void);
    int largest(void);
};

int Set::largest(void)
{
    if (m >= n)
        return m;
    else
        return n;
}
void Set::input(void)
{
    cout << "Enter the Value of m and n :" << endl;
    cin >> m >> n;
}
void Set::display(void)
{
    cout << "The latgest Value is : "
         << largest() << endl;
}
int main()
{
    Set A;
    A.input();
    A.display();
    return 0;
}
