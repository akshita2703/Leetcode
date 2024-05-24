// backtrackingg
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// backtrackingg
// [2 4 6] k = 2 

// step for recursion


//not pick []        
//map [] -- map m check kro agr nums[i]+2 ya nums[i]-2 present toh nhi agr dono present nhi h toh pick krlo  
//  pick (map m nhin h ) [2] -- abh further call --call khtm hone baad map se hta do
                   

    void solve(int i, int n , int k, unordered_map<int,int>&mp,vector<int>&nums,int &result){
        if(i>=n){ // base case
            result++;
            return;
        }
        // not take
        solve(i+1,n,k,mp,nums,result);
        if(!mp[nums[i]+k] && !mp[nums[i]-k]){
            // agr map m nhi h toh lele
            mp[nums[i]]++;// do 
            solve(i+1,n,k,mp,nums,result); // explore
            mp[nums[i]]--;// undo // backtrack 

        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 0;
        int n = nums.size();

        unordered_map<int,int> mp;
        solve(0,n,k,mp,nums,result);
        return result -1; // empty subset ka ek count substract kiya 
        
    }
};

int main(){
    Solution obj;
    vector<int> nums = {2,4,6};
    int k = 2;
    int ans = obj.beautifulSubsets(nums,k);
    cout<< ans;
    return 0;
}
