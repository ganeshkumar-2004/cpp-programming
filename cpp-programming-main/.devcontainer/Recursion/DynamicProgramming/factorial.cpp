#include <iostream>
using namespace std;
int Factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * Factorial(n - 1);
}
int main(){
    int n;
    cout<<"Enter a number that you want to find the Factorial : "<<" ";
    cin>>n;
    cout<<"Factorial of the number is : "<<Factorial(n)<<endl;
    return 0;
}