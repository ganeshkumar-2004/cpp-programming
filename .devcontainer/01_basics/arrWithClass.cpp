#include <iostream>
using namespace std;
const int m = 50;
class Items
{
    int itemCode[m];
    float itemPrice[m];
    int count;

public:
    void Cnt(void) { count = 0; }
    void setItem(void);
    void displaySum(void);
    void remove(void);
    void displayItem(void);
};
void Items::setItem(void)
{
    cout << "Enter Item code : ";
    cin >> itemCode[count];
    cout << endl;
    cout << "Enter Item cost :";
    cin >> itemPrice[count];
    count++;
}
void Items::displaySum(void)
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum = sum + itemPrice[i];
    }
    cout << " \nTotal Value : " << sum << endl;
        
}
void Items::remove(void)
{
    int a;
    cout << " Enter Item code : ";
    cin >> a;
    for (int i = 0; i < count; i++)
    {
        if (itemCode[i] == a)
            itemPrice[i] = 0;
    }
}
void Items::displayItem(void)
{
    cout << "\ncode Price\n";
    for (int i = 0; i < count; i++)
    {
        cout << "\n"
             << itemCode[i];
        cout << "  " << itemPrice[i] << endl;
    }
}
int main()
{
    Items order;
    order.Cnt();
    int x;
    do
    {
        cout << " \n  You can do the following : "
             << "Enter appropriate Number " << endl;
        cout << "\n1 : Add an Item ";
        cout << "\n2 : Dispay total value " << endl;
        cout << "\n3 : delete an item  " << endl;
        cout << "\n4 :display all itme " << endl;
        cout << "\n5 : Quit :" << endl;
        cout << "\n What is the your option ? " << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            order.setItem();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displayItem();
            break;
        case 5:
            break;
        default:
            cout << " Error in input : try again ";
        }

    } while (x != 5);
    return 0;
}