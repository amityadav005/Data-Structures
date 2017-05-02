#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node * left;
};
Node* newNode(int data){
    Node* temp = (Node * )malloc(sizeof(Node*));
    temp->data = data;
    temp->left=temp->right=NULL;
    return temp;
}
void flat(Node *root,Node**prev, Node**head){
    if(root==NULL)
        return;
    flat(root->left,prev,head);
    if(*prev==NULL){
        *prev = root;
        *head = root;
    }
    else
        (*prev)->right=root;
    *prev = root;
    flat(root->right,prev,head);
}
int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    Node* head;Node* prev=NULL;
    flat(root,&prev,&head);
    cout<<head->right->data;
    return 0;
}//
// Created by Amit on 12/14/2016.
//

