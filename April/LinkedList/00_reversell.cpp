#include<bits/stdc++.h>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode * next;
//     ListNode():val(0), next(nullptr){}
//     ListNode(int val):val(val), next(nullptr){}
//     ListNode(int val, ListNode *next):val(val), next(next){}
// };

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr);
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val, ListNode *next):val(val),next(next){}
};

int main(){
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int m;
        cin>>m;
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        for(int j =0;j<m;j++){
            int val;
            cin>>val;
            temp->next = new ListNode(val);
            temp = temp->next;
        }

    }
}
