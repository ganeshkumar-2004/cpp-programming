#include<iostream>
using namespace std;
class complex{
    int a , b;
public:
    complex(){};
    complex(int a,int b){
        this->a=a;
        this->b=b;
    }
    void display(void){
        cout<<"The complex number is : "
            <<a<<"+"<<b<<"i"<<endl;
    }
    complex operator +(complex& Num){
        complex temp;
        temp.a=a+Num.a;
        temp.b=b+Num.b;
        return temp;
    }
    complex operator -(complex& Num){
        complex temp;
        temp.a=a-Num.a;
        temp.b=b-Num.b;
        return temp;
    }
    complex operator *(complex& Num){
        complex temp;
        temp.a=a*Num.a;
        temp.b=b*Num.b;
        return temp;
    }
};
 
int main(){
    complex Num1(9,8),Num2(5,6),Num3,Num4,Num5;
    Num1.display();
    Num2.display();
    Num3=Num1+Num2;
    Num3.display();
    Num4=Num1-Num2;
    Num4.display();
    Num5=Num1*Num2;
    Num5.display();
    
   return 0;
}
