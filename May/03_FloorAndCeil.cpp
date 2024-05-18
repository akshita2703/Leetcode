//{ Driver Code Starts

https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
    // code here
    int f=-1;
    int c=-1;
    sort(arr,arr+n);
    
    for(int i =0;i<n;i++){
        if(arr[i]<=x){
            c = arr[i];
        }
        
    }
    for(int i = n-1;i>=0;i--){
        if(arr[i]>=x){
            f = arr[i];
        }
    }
    return {c,f};
}