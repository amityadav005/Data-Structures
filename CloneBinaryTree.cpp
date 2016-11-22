//
// Created by Amit on 11/21/2016.
//

#include <iostream>
#include <malloc.h>

using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
    Node* ran;
};
struct random{
    Node * key;
    Node * val;

};
random map[100];
int size = -1;
void put(Node * key, Node * val){
    size++;
    map[size].key=key;
    map[size].val=val;
}
Node* get(Node* val) {
    Node *temp;
    for (int i = 0; i < size; i++) {
        if (map[i].val == val) {
            temp = map[i].key->ran;
        }
    }
    return temp;
}

Node * newNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    temp->ran = NULL;
    return temp;
}
void populateRan(Node * root){
    if(root==NULL)
        return;
    populateRan(root->left);
    root->ran = get(root->ran);
    populateRan(root->right);
}

Node* clone(Node * root){
    if(root==NULL)
        return NULL;
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = root->data;
    put(root, temp);
    temp->left = clone(root->left);
    temp->right = clone(root->right);
    return temp;
}
void inorder(Node * root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node * root  =newNode(10);
    root->ran=root->left;
    root->left = newNode(20);
    root->right = newNode(30);
    //Node * temp = clone(root);
    //populateRan(temp);
    //inorder(temp);
    cout<<root->ran->data;
}