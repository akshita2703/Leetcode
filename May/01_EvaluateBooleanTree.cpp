// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/
#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root){
        if(root->val==0||root->val==1){  // root hi 0 ya 1 toh ye leaf node h 
            return root->val==1;
        }
        else if(root->val ==2){
            return solve(root->left)||solve(root->right); // root 2 mtlb OR operator
        }
        else{
            return solve(root->left)&& solve(root->right); // root 3 mtlb AND operator
        }
        return false;
    }
    bool evaluateTree(TreeNode* root) {
        
       return solve(root);
    }
};