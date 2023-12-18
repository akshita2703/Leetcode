//https://leetcode.com/problems/delete-node-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
    

        while(node->next->next){
            
           
                ListNode*nextt = node->next;
                int k = nextt->val;
                node->val= k;
           
            node=node->next;
            
        }
        if(node->next->next==NULL){
            node->val=node->next->val;
            node->next=NULL;


        }
        
    }
};



// void deleteNode(ListNode* node) {
//         node->val = node->next->val;
//         node->next=node->next->next;
        
//     }