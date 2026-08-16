#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>NSL(int arr[], int n ){
     vector<int>v(n);
     stack<pair<int,int>>s;
     for (int i = 0; i < n; i++)
     {
        while(!s.empty() && s.top().first>=arr[i]){
            s.pop();
        } 
        if(s.empty())
          v[i]=-1;
        else
           v[i]=s.top().second;
       
       s.push({arr[i],i});
     }
     return v;
}
vector<int>NSR(int arr[], int n ){
     vector<int>v(n);
     stack<pair<int,int>>s;
     for (int i = n-1; i >=0; i--)
     {
        while(!s.empty() && s.top().first>=arr[i]){
            s.pop();
        } 
        if(s.empty())
          v[i]=n;
        else
           v[i]=s.top().second;
       
       s.push({arr[i],i});
     }
     return v;
}

int main(){
    int arr[]={6,2,5,4,5,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>indexNSL=NSL(arr,n);
    vector<int>indexNSR=NSR(arr,n);
    cout<<" Next Samllest to Left in the Array : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<indexNSL[i]<<" ";
    }
    cout<<endl;
    cout<<" Next Samllest to Right in the Array : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<indexNSR[i]<<" ";
    } 
    cout<<endl;
    int Width[n];
    cout<<" Width of the Histogram : "<<endl;
     for (int i = 0; i < n; i++)
    {    
        Width[i]=indexNSR[i]-indexNSL[i]-1;
        cout<<Width[i]<<" ";
    }
     cout<<endl;
    int Area[n];
    cout<<" Maximun Area of Histogtam is :"<<endl;
     for (int i = 0; i < n; i++)
    {    
        Area[i]=arr[i]*Width[i];
        cout<<Area[i]<<" ";
    }
    return 0;
}


