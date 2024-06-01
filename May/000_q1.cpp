
#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&arr){
    int n = arr.size();
    if(n==1)return arr[0];

    unordered_map<int,int> mp;
    for(int i =0;i<n;i++){
        mp[arr[i]]++;
    }
    for(int i =0;i<n;i++){
        if(mp[arr[i]]==1){
            return arr[i];
        }
    }
    return -1;
    
    
}

int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int ans = solve(arr);
    cout<<ans<<endl;

}