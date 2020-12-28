// Question https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/

#include <bits/stdc++.h>
using namespace std;

void zigZag(int a[], int n) {
    
    int flag=0;
    for(int i=0;i<n-1;i++) {
        if(a[i]>a[i+1] and flag==0) {
            swap(a[i],a[i+1]) ;
        }
        else if(a[i]<a[i+1] and flag) {
            swap(a[i],a[i+1]) ;
        }
        flag = !flag ;
    }
    
}


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        zigZag(arr, n);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}