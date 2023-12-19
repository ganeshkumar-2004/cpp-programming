#include <iostream>
using namespace std;
int RWT(int arr[], int n)
{
    int maxL[n];
    maxL[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxL[i] = max(maxL[i - 1], arr[i]);
    }
    cout << "Maximum Value of array into the Left side : "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << maxL[i] << " ";
    }
    cout << endl;
    int maxR[n];
    maxR[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxR[i] = max(maxR[i + 1], arr[i]);
    }
    cout << "Maximum Value of array into the Right side : "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << maxR[i] << " ";
    }
    cout << endl;
    int Wmin[n];
    for (int i = 0; i < n; i++)
    {
        Wmin[i] = min(maxL[i], maxR[i]);
    }
    cout << "Decide the level of water according to Minimum value of left or right array's value : "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << Wmin[i] << " ";
    }
    cout << endl;
    int Water[n];
    for (int i = 0; i < n; i++)
    {
        Water[i] = Wmin[i] - arr[i];
    }
    cout << "Actual water stored on the Building : "<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << Water[i] << " ";
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + Water[i];
    }

    return sum;
}
int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int Ans = RWT(arr, n);
    cout << "Total unit of water : " ;
    cout << Ans << endl;

    return 0;
}
