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
// used post order traversal to solve
//  Initial Tree:
//         1
//       /   \
//      2     3
//     /     / \
//    2     2   4
   
// Step-by-Step Deletion:
// 1. Traverse to [2 (leaf with value = 2)], delete.
//         1
//       /   \
//      2     3
//     /     / \
//   null   2   4

// 2. Now, [2 (leaf with value = 2)], delete.
//         1
//       /   \
//      2     3
//     /     / \
//   null  null  4

// 3. Finally, [2 (leaf with value = 2)], delete.
//         1
//       /    \
//   null     3
//          /   \
//        null   4

// Final Tree:
//    1
//     \
//      3
//       \
//        4

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x): val(x),left(nullptr),right(nullptr){};
    TreeNode(int x , TreeNode *left, TreeNode *right): val(x),left(left),right(right){};
};


TreeNode* solve(TreeNode* root,int target){
    if(!root)return NULL;
    root->left = solve(root->left,target);
    root->right = solve(root->right,target);
    if(!root->left && !root->right && root->val == target)return NULL;
    return root;
}
TreeNode* removeLeafNodes(TreeNode* root, int target) {
    return solve(root,target);   
}
TreeNode* makeTree(vector<int> & levelOrder,TreeNode*root,int i ,int n){
   
    if(i<n){
        TreeNode* temp = nullptr;
         if(levelOrder[i]!=-1){
             
      
            temp = new TreeNode(levelOrder[i]);
            root = temp;

            // insert left child 
            root->left = makeTree(levelOrder,root->left,2*i+1,n);
            //insert right child
            root->right = makeTree(levelOrder,root->right,2*i+2,n);

         }
        
       


        
    }
    return root;
}

void lvlOrder(TreeNode* root){
    if(!root)return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        
        TreeNode* temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);

    }
}




int main(){
   
    int n ;
    cin>>n;
    vector<int> levelOrder;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        levelOrder.push_back(k);

    }
    TreeNode* root = makeTree(levelOrder,root,0,n);
    TreeNode* root1 = removeLeafNodes(root,2);
    cout<< "levelorder traversel ";
    lvlOrder(root1);
}