#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

// Helper function to allocate a new node
Node* newNode(int data){
    Node* n = new Node();
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    return n;

}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 

Node* insert(Node* root, int data ){
    // If the tree is empty, return a new node
    if(root == nullptr){
        return newNode(data);
    }
    Node *temp;
    // Otherwise, recur down the tree
    if(data < root->data){
        temp = insert(root->left,data);
        root->left = temp;
        temp->parent = root;
    }
    else{
        temp = insert(root->right,data);
        root->right = temp;
        temp->parent = root;
    }
    // return the unchanged root pointer
    return root;
}
// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your 
// findInOrderSuccessor function on

Node* getNodeByKey(Node* root, int data){
    Node* current = root;
    while(current){
        if(data == current->data){
            return current;
        }
        if(data < current->data){
            current = current->left;
        }
        else{
            current =  current->right;
        }
    }
    return nullptr; // If not found, return nullptr
}

Node* findtheminkey(Node *inputNode){
    while(inputNode->left){
        inputNode = inputNode->left;
    }
    return inputNode;
}
Node* findInOrderSuccessor( Node *inputNode )
{
   // your code goes here
   if(inputNode->right!=nullptr){
    return findtheminkey(inputNode->right);
   }

   Node *child = inputNode;
   Node *ancestor = inputNode->parent;
   while(ancestor!=nullptr && child == ancestor->right){
    child = ancestor;
    ancestor = child->parent;
   }
   return ancestor;
}

// Comment out main() before running tests
int main() {
  return 0;
}
