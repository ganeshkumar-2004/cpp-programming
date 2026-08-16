#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 vector<int>NGL(int arr[], int n){
    vector<int>v(n);
    stack<pair<int,int>>s;
    for (int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top().first<=arr[i]){
            s.pop();
        }
         if(s.empty())
            v[i] = -1;
        else 
            v[i] = s.top().second;

        s.push({arr[i],i});  
    }
    
  return v;

 }
 int main(){
   int arr[]= {100,80,60,70,60,75,85};
   int n=sizeof(arr)/sizeof(arr[0]);
   vector<int>indexNGL=NGL(arr,n);
   cout<<" Next greatest to Left in the Array : "<<endl;
   for (int i = 0; i < n; i++)
   {
    cout<<indexNGL[i]<<" ";
   }
   cout<<endl;
    cout<<" Stock Spane Solution  : "<<endl;
    int SSP[n];
   for (int i = 0; i < n; i++)
   {      
        SSP[i] = i - indexNGL[i];
    cout<<SSP[i]<<" ";
   }


 }