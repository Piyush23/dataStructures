#include "iostream"
#include "bits/stdc++.h"
using namespace std;

bool comp(int x, int y){
    return x>y;
}

int main(){
    vector<int> v = {3,5,6,1,8,9};
    
    //default max heap
    priority_queue<int> pq1 (v.begin(), v.end());
    cout<<pq1.top()<<endl;
    
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq2 (v.begin(), v.end());
    cout<<pq2.top()<<endl;
    
    return 0;
}