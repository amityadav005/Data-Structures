//
// Created by Amit on 11/17/2016.
//
#include <iostream>
#include<memory>
#include <malloc.h>
using namespace std;
//static int count=1;
struct Node{
    int data;
    Node* left;
    Node *right;
};
Node * newNode(int data){
    Node * temp =  (Node *)malloc(sizeof(Node));
    temp->data= data;
    temp->left=NULL;
    temp->right=NULL;
}
void subtract(Node * root, int * count){
    if(root==NULL)
        return;
    subtract(root->left,  count);
    if(*count==3) {
        cout<<root->data<<" ";
    }
    //cout<<*count<<"::";
    (*count)++;//= *count+1;
    //cout<<*count<<"::";
    subtract(root->right, count);

}
void inorder(Node * root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main(){
 int count = 1;
    Node * root =newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(8);
    root->right->left = newNode(12);
    root->right->right = newNode(18);
    inorder(root);
    cout<<endl;
    subtract(root, &count);
   // inorder(root);
}

