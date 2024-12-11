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
    void reorderList(ListNode* head) {

        // step1 - find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the Second half 

        ListNode* prev = NULL;
        ListNode* curr = slow->next;
       







        while(curr){
            ListNode* nextNode = curr->next;
           curr->next = prev;
           prev = curr;
           curr= nextNode;
           
        }
        slow->next = NULL;
        // step3 : Merge
        ListNode* first = head;
        ListNode* second = prev;

        while(first && second){
            ListNode* nextFirst =  first->next;
            ListNode* nextSecond =  second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
};