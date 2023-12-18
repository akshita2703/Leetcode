
//https://leetcode.com/problems/remove-linked-list-elements/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removenode(ListNode* ptr, int target){
        // base case
        if(ptr==NULL){
            return NULL;
        }
        ListNode*returnNode=removenode(ptr->next,target);
        if(ptr->val==target){
            return returnNode;
        }
        else{
            ptr->next = returnNode;
            return ptr;
        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        return removenode(head,val);
    }
};