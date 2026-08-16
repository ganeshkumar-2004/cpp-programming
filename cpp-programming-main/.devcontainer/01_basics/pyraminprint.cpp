#include <iostream>
using namespace std;
int main()
{
    int i, j, Line;
    cout << "Enter the number of line : ";
    cin >> Line;
    for (i = 1; i <= Line; i++)
    {
        for (j = 1; j <= (2 * i) - 1; j++)
        {
            if (j >=Line + 1 - i && j <=Line - 1 + i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}