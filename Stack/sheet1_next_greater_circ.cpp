// Question : https://leetcode.com/problems/next-greater-element-ii/


#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& a) {
    int n = a.size() ;
    
    if(n==0) {return a;}
    vector<int> sol(n) ;
    stack<int> s ;
    
    s.push(0) ;
    
    for(int i=1;i<n;i++) {
        while(s.size() and a[i]>a[s.top()]) {
            sol[s.top()] = a[i] ;
            s.pop() ;
        }
        s.push(i) ;
    }
    
    for(int i=0; s.size() and i<s.top();i++) {
        while(s.size() and a[s.top()]<a[i]) {
            sol[s.top()] = a[i] ;
            s.pop() ;
        }
    }
    
    while(s.size()) {
        sol[s.top()] = -1;
        s.pop() ;
    }
    
    return sol ;
}

int main() {
    int t; cin>>t;
    while(t--) {
        
        int n; cin>>n;
        vector<int> a(n);

        for(int i=0;i<n;i++) cin>>a[i];
        
        vector <int> res = nextGreaterElements(a);
        for (int i : res) cout << i << " ";
        cout<<endl;
    
	return 0;
}