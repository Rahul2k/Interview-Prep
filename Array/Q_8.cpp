// Question : https://www.geeksforgeeks.org/chocolate-distribution-problem/

#include<bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t; cin>>t;
	while(t--) {
	    int n,m; cin>>n;
    	int a[n] ;
    	
    	for(int i=0;i<n;i++) cin>>a[i] ;
    	cin>>m;
    	
    	sort(a,a+n) ;
    	
    	int s = 0, e = m-1 ;
    	int diff = INT_MAX ;
    	
    	while(e<n) {
    	    
    	    diff = min(diff,a[e]-a[s]) ;
    	    e++,s++ ;
    	}
    	cout<<diff<<'\n' ;    
	}

	return 0;
}