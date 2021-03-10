#include<bits/stdc++.h>
using namespace std;



int main() {

    int t; cin>>t;
    while(t--) {

        int n; cin>>n;
        int a[n] ;

        for(int i=0;i<n;i++)  cin>>a[i] ;
        sort(a,a+n) ;
        map<int,int> mp ;

        for(int i=0;i<n;i++) {

            mp[a[i]] ++ ;
        }

        int cnt = 0 ;
        for(auto i: mp) {
            if(i.second>1) {
               mp[i.first+1]++ ;
               mp[i.first]-- ; 
            }
            cnt++ ;
        }

        cout<<cnt<<endl ;

    }
}