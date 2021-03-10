#include <bits/stdc++.h>
using namespace std;


int find_lps(string& s, int i, int j, vector<vector<int>>& dp) {
    
    if(i>j) return 0 ;
    if(i==j) return 1 ;
    if(dp[i][j]!=-1) return dp[i][j] ;
    
    int t = max(find_lps(s,i,j-1,dp),find_lps(s,i+1,j,dp)) ;
    
    if(s[i]==s[j]) return dp[i][j] = 2 + find_lps(s,i+1,j-1,dp) ;
    else return dp[i][j] = t ;
}

int lps(string s, int n) {

    vector<vector<int>> dp(n,vector<int>(n,-1)) ;
    int n = s.length() ;
    
    for(int i=0; i<n; i++) dp[i][i] = 1 ;
    
    return find_lps(s,0,n-1,dp) ;
}


int main() {

    string a; cin>>a;
    int n = a.length() ;
    
    cout<<lps(a,n)<<'\n' ;

    return 0;
}
