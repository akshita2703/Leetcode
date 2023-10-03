#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int sum1 =  n *(n+1) /2;
        for(int i = 0 ;i<nums.size();i++){
            sum = sum+nums[i];

        }
        int ans = sum1-sum;
        return ans;
        
        
    }
};

int main(){
    Solution answer;
    vector<int> nums = {0, 1, 3}; // Example input
    int missing = answer.missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    return 0;

}