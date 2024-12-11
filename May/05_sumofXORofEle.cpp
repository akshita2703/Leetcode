
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {
public:
    // Definately we can use pick not pick concept of recursion 
    // //                      (14)  [5 1 6] (14)
    //                         /               \
    // //       (6) pick [5] (8)                (8) not pick [] (6)   
    //             /       \                      /             \
    // //  (2) [5 1](4)   (3) [5](5)         (7)[1](1)         (6)[](0)
    //         /     \      /     \           /     \          /    \ 
    // // [5 1 6]  [5 1]  [5 6]     [5]   [1 6]      [1]    [6]      []

    // // (2)        (4)  (3)     (5)     (7)        (1)   (6)      (0)
    
    
    
    int helper(vector<int>&nums,int level, int curr){
        if(level==nums.size())return curr;
        // pick 
        int pick = helper(nums,level+1,curr^nums[level]);
        // not pick 
        int Notpick = helper(nums,level+1,curr);

        return pick + Notpick;

    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,0);
    }
};