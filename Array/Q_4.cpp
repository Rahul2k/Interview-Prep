// Question : https://www.geeksforgeeks.org/equilibrium-index-of-an-array/

#include <iostream>
using namespace std;


int equilibriumPoint(int a[], int n) {

    if(n==1) return 1 ;
    long long l_sum = 0, sum = 0;

    for(int i=0;i<n;i++) sum+=a[i] ;
    l_sum = a[0] ;
    int found=0;
    
    for(int i=1;i<n;i++) {
        if(sum - l_sum-a[i] == l_sum ) {
            return i+1;
        }
        l_sum+=a[i] ; 
    }
    
    return -1 ;

}

int main() {

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}

