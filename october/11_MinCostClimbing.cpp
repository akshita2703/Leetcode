
// https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=daily-question&envId=2023-10-13

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int costi(vector<int>& cost , int i ,  vector<int> &dp){
        if(i==1|| i==0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = costi(cost,i-1 , dp) + cost[i-1];  
        int right = costi(cost , i-2 , dp)+cost[i-2];
        int ans = min(left,right);
        return dp[i] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
     
        return costi(cost , n , dp);
    }
};


int main() {
    Solution obj;
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int ans = obj.minCostClimbingStairs(cost);
    cout<< ans<<endl;
    return 0;
}
