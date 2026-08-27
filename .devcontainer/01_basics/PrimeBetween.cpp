#include<iostream>
#include<math.h>
using namespace std;
 
// Print all Prime numbers Between two given number ...
int isPrime(int n){
    int  i = 2, s;
    s =(int) sqrt(n);
    for (i; i <= s; i++)
    {
        if (n % i == 0)
            break;
    }
    if (i == s + 1)
        return 1;
    else
        return 0;
    
}
int main()
{
    int a,b;
    cout<<"Enter start and and end number : ";
    cin>>a >>b;
    for(int i = a; i <= b ; i++){
       if(isPrime(i))
        cout<<i<<" ";
    }
    return 0;
}
