// https://leetcode.com/problems/distribute-coins-in-binary-tree/?envType=daily-question&envId=2024-05-18/


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
// //  0
//    0  0
//   2  2  2
//  l=0 r=0
// moves += l+r
// 0 
// return (0+0+2)-1 = 1

    // l=2          0       r= -1     moves = abs(2)+abs(-1) = 3 ans 
    //            3   0

    // l=0 r=0                   l=0 r =0
    // moves +=0                 moves+=0
    // 0                    
    //  return (0+0+3)-1 = 2     return  0+0+0 - 1  = -1




    int solve(TreeNode* root,int &moves){
        
        if(!root)return 0;
        int l = solve(root->left,moves);
        int r = solve(root->right,moves);
        moves+= abs(l)+abs(r);
        return (l+r+root->val)-1;
        
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        solve(root,moves);
        return moves;
    }
};