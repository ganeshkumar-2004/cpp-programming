#include<iostream>
using namespace std;

 int seclargest(int arr[], int n ){
    int largest = arr[0];
    int seclargest = arr[1];
    for(int i = 1; i<n ; i++){
        if(arr[i]>largest){
            seclargest=largest;
            largest = arr[i];
        }
        if(arr[i]<largest && arr[i] > seclargest)
            seclargest = arr[i];
    }
    return seclargest;
 }
int main(){
    int arr[] = {16,4,5,20,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int seclar = seclargest(arr,n); 
    cout<<"second largest element : " <<seclar;
    return 0;
}