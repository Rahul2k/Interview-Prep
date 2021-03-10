#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL) ;

    int t; cin>>t;
    while(t--) {

        string s; cin>>s;
        int n = s.length() ;
        int cnt =0;

        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]){
                cnt++ ;
            }
            else if(i<n-2 and s[i]==s[i+2]) {
                cnt++ ;
            }
        }   

        cout<<cnt<<'\n' ;

    }

}