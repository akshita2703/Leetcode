/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    Node *solve(Node *parent) {
        Node *p = parent, *prev = NULL;
        while (p) {
            if (p->child) {
                Node *temp = p->next;
                Node *tail = solve(p->child);
                p->next = p->child;
                p->child->prev = p;
                p->child = NULL;
                if (temp) {
                    temp->prev = tail;
                }
                p = tail;
            }
            prev = p;
            p = p->next;
        }
        return prev;
    }

    Node* flatten(Node* head) {
        if (!head) return head;
        solve(head);
        return head;  
    }
};



// Time complexity: O(n)
// Space complexity: O(1)