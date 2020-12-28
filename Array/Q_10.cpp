#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int t; cin>>t;
    while (t--) {
        
        int n; cin>>n;
        int a[n] ;
        
        for(int i=0 ;i<n; i++) cin>>a[i] ;
        
        int right[n] ={} ;
        int left[n] ={};
        
        int leftmax = -1, rightmax = -1;
        
        for(int i=0; i<n; i++) {
            
            if(a[i]>leftmax) leftmax = a[i] ;
            left[i] = leftmax ;
        }
        
        for(int i = n-1; i>=0; i--) {
            if(a[i]>rightmax) rightmax = a[i] ;
            right[i] = rightmax ;
        }
        
        int water = 0;
        
        for(int i=0; i<n; i++) {
            water += max(min(left[i],right[i])-a[i], 0) ;
        }
        
        cout<<water<<"\n" ;
    }
    
	return 0;
}