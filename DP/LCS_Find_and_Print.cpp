#include <bits/stdc++.h>
using namespace std;

int main() {

    string a,b; cin>>a>>b;
    int n = a.length(), m = b.length() ;
    int lcs[n+1][m+1] = {} ;
    
    // Finding LCS
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
                
            if(a[i-1]==b[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1] ;
            }
            else {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]) ;
            }
        }
    }

    // Printing LCS from lcs array
    string sol = "" ;
    int i = n, j = m ;

    while(i>0 and j>0) {
    
        if(a[i-1]==b[j-1]) {
            sol += a[i-1] ;
            i--, j-- ;
        }
        else {
            if(lcs[i-1][j]==lcs[i][j]) {
                i-- ;
            }
            else j-- ;
        }
    }

    reverse(sol.begin(),sol.end()) ;
    cout<<lcs[n][m]<<'\n'<<sol ;
    return 0 ;
}
