//https://leetcode.com/problems/number-of-good-pairs/?envType=daily-question&envId=2023-10-03

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums){
        vector<int> freq(100); // 1 2 3 1 1 3 
        int an =0;
        for(auto &it:nums){
            freq[it-1]++;  // 3 1 2  
            
        }
        for(auto a:freq){
            an+=(a-1)*(a)/2;
        }
        return an;
        
    }
};

int main(){
    Solution obj;
    vector<int> nums{1,2,3,4,1,3,4,5};
    cout<< obj.numIdenticalPairs(nums);

    return 0;
}