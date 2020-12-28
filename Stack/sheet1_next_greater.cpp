// Question : https://www.geeksforgeeks.org/next-greater-element/


#include<bits/stdc++.h>
using namespace std;

vector <long long> nextLargerElement(long long a[], int n){

    vector<long long> sol(n) ;
    stack<int> s ;
    s.push(0) ;
    
    for(int i=1; i<n;i++) {
        while(s.size() and a[i]>a[s.top()]) {
            sol[s.top()] = a[i] ;
            s.pop() ;
        }
        s.push(i) ;
    }
    
    while(s.size()) {
        sol[s.top()] = -1;
        s.pop() ;
    }
    
    return sol ;
}

int main() {
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        long long arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    
	return 0;
}