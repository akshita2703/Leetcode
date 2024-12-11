#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n*(n+1))/2;
        int fs =0;
        int s =1;
        int e = n;
        while(s<=e){
            int mid = s+(e-s)/2;
            int sum1 = (mid*(mid+1))/2;
            int sum2 = sum - sum1 + mid;
            if(sum1==sum2){
                return mid;
            }
            else if(sum1>sum2){
                e=mid-1;
            }
            else{
                s = mid+1;
            }

        }
        return -1;

        
    }
};

int main(){
    Solution obj;
    int n;
    cout<<"enter n ";
    cin>>n;
    int ans = obj.pivotInteger(n);
    cout<< " Answer is " << ans;
    return 0;

}