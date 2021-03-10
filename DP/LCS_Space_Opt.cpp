#include <bits/stdc++.h>
using namespace std;

int main() {

    string a,b; cin>>a>>b;
    int n = a.length(), m = b.length() ;
    int lcs[m+1] = {} ;
    
    for(int i=1; i<=n; i++) {

        int temp = lcs[0] ;
        for(int j=1; j<=m; j++) {
                
            int temp2 = lcs[j] ;   

            if(a[i-1]==b[j-1]) {
                lcs[j] = 1 + temp ;
            }
            else {
                lcs[j] = max(lcs[j],lcs[j-1]) ;
            }
            temp = temp2 ;
        }
    }

    cout<<lcs[m] ;

}
