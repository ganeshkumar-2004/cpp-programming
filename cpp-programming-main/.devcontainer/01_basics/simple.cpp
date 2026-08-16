#include <iostream>
using namespace std;
class Item
{
    int Id;
    float cost;

public:
    void setData(int a, float b);
    void getData();
};
void Item::setData(int a, float b)
{
    Id = a;
    cost = b;
}
void Item::getData()
{
    cout << "The Id of the item is : " << Id << endl;
    cout << "The cost of the item : " << cost << endl;
}
int main()
{
    Item x, y;
    x.setData(100, 200);
    x.getData();
    y.setData(101, 300);
    y.getData();
}
