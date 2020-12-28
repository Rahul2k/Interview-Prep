// Question : https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/


#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
	
 	sort(arr,arr+n) ;
    sort(dep,dep+n) ;
	
	int i = 0, j = 0, k =0;
	int max_k=0;
	while(i<n and j<n) {
	    
	    if(arr[i]<dep[j]) {
	        k++ ,i++;
	    }
	    else if(arr[i]>dep[j]) {
	        k--, j++ ;
	    }
	    else if(arr[i]==dep[j]) {
	        k++,i++;
	    }
	    max_k = max(k,max_k);
	}
	
	return max_k ;
}

int main() {

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int arr[n];
        int dep[n];

        for(int i=0;i<n;i++) cin>>arr[i];

        for(int j=0;j<n;j++) cin>>dep[j];
        
        cout <<findPlatform(arr, dep, n)<<endl;
    } 

    return 0;
}