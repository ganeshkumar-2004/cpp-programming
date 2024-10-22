#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> & v){
    if(v.size()==0)
        return;
    else{
        int m = v[v.size()-1];
        v.pop_back();
        sort(v);
        insert(v,m);
    } 
    void insert(vector<int> & v, int temp){
        if (v.size()==0 || v[v.size()-1]<=temp)     
        {
           v.push_back(temp);
           return;
        }
        else {
            
        }
        
    }

}