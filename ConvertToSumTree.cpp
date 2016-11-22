#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node* right;
};

Node * newNode(int data){
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left=temp->right = NULL;
    return temp;
}
int  convert(Node * root){
    if(root==NULL)
        return 0;
    int old = root->data;
    root->data = convert(root->left)+convert(root->right);
    return old+root->data;

}
void inorder(Node * root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node * root;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    inorder(root);
    convert(root);
    cout<<endl<<"after conversion::"<<endl;
    inorder(root);
}


