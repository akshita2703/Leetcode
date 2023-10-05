// https://leetcode.com/problems/majority-element-ii/?envType=daily-question&envId=2023-10-05

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int countMaj = nums.size()/3;
        unordered_map<int,int> map;
        vector<int> output;
        for(auto num : nums){
            map[num]++;
        }
        for(auto num : map){
            if(num.second>countMaj){
                output.push_back(num.first);
            }
        }
        return output;
    }
};

int main(){
    Solution obj;
    vector<int> nums{3,3,3,2,4,1};
    vector<int> result = obj.majorityElement(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}