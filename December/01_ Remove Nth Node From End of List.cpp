// Remove Nth Node From End of List- https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
    int getLength(ListNode *head){
        ListNode*temp=head;
        int l=0;
        while(temp!=NULL){
            l++;
            temp=temp->next;

        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=getLength(head);
        
        int k = len-n;
        int o=0;
        ListNode*temp=head;
        
        if (k == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while(temp!=NULL){
            if(o==k-1){
                ListNode*nextNode=temp->next;
                temp->next=nextNode->next;
                delete nextNode;

            }
            temp=temp->next;
            o++;
        }
        return head;
        
    }
};

//Approach - creating get length function to find the length of the  linkedlist then traverse the list and the delete the node except when the node which has to be deletes len-n=0 to hsandle this case add new condition
