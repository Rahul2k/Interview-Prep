//Question : https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/

#include<bits/stdc++.h>
using namespace std;
int main() {
    
    int t; cin>>t;
    while(t--) {
        
        int d,n; cin>>n>>d;
        int a[n] ;
        
        for(int i=0;i<n;i++) cin>>a[i] ;
        
        sort(a,a+n) ;
        int s=0,e=1 ;
        int ans =0;
        
        while(s<n and e<n) {
            if(a[e]-a[s]==d){
                ans=1;
                break;
            }
            else if(a[e]-a[s] > d) {
                s++;
            }
            else {
                e++ ;
            }
        }
        
        if(ans)  cout<<ans<<'\n' ;
        else cout<<-1<<'\n' ;
        
    }

	return 0;
}