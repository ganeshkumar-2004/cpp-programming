#include <iostream>
using namespace std;
class FixedDeposit
{
private:
    int principl;
    int year;
    float Rate;
    float ReturnValue;

public:
    FixedDeposit() {}
    FixedDeposit(int p, int y, float r = 0.12);
    FixedDeposit(int p, int y, int r);
    void display(void);
};

FixedDeposit::FixedDeposit(int p, int y, float r)
{
    principl = p;
    year = y;
    Rate = r;
    ReturnValue = principl;
    for (int i = 0; i <= y; i++)
    {
        ReturnValue = ReturnValue * (1.0 + r);
    }
}
FixedDeposit::FixedDeposit(int p, int y, int r)
{
    principl = p;
    year = y;
    Rate = r;
    ReturnValue = principl;
    for (int i = 0; i <= y; i++)
    {
        ReturnValue = ReturnValue * (1.0 + float(r) / 100);
    }
}
void FixedDeposit::display(void)
{
    cout << "\n"
         << "Principle amount = " << principl << "\n"
         << "Return Value = " << ReturnValue << endl;
}
int main()
{
    FixedDeposit FD1, FD2, FD3;
    int p;
    int y;
    float r;
    int R;
    cout << "Enter the 'amout' ,'Period','interest Rate'(in %) : " << endl;
    cin >> p >> y >> R;
    FD1 = FixedDeposit(p, y, R);
    cout << "Enter the 'amout' ,'Period','interest Rate'(in desimal form) : " << endl;
    cin >> p >> y >> r;
    FD2 = FixedDeposit(p, y, r);
    cout << "Enter the 'amout' ,'Period' : " << endl;
    cin >> p >> y;
    FD3 = FixedDeposit(p, y);
    cout << " Deposit 1: ";
    FD1.display();
    cout << endl;
    cout << " Deposit 2: ";
    FD2.display();
    cout << endl;
    cout << " Deposit 3: ";
    FD3.display();
    return 0;
}