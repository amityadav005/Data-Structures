#include <iostream>
#include <malloc.h>
#include<map>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node* ran;
};
void printInorder(node* node)
{
    if (node == NULL)
        return;

    /* First recur on left sutree */
    printInorder(node->left);

    /* then print data of Node and its random */
    cout << "[" << node->data << " ";
    if (node->ran == NULL)
        cout << "NULL], ";
    else
        cout << node->ran->data << "], ";

    /* now recur on right subtree */
    printInorder(node->right);
}

node* newNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left=temp->right=temp->ran =NULL;
    return temp;
}
node*  copyleftright(node* root, map<node*, node* > &m){
    if(root==NULL)
        return NULL;
    node* cloneNode = newNode(root->data);
    m[root] = cloneNode;
    cloneNode->left = copyleftright(root->left, m);
    cloneNode->right =copyleftright(root->right, m);

}
void copyRandom(node* root,node* cloneNode, map<node*, node* > &m){
    if (cloneNode == NULL)
        return;
    cloneNode->ran = m[root->ran];
    copyRandom(root->left, cloneNode->left, m);
    copyRandom(root->right, cloneNode->right, m);
}
node* cloneTree(node* root){
    map<node*, node* >m;
    node* cnode = copyleftright(root, m);
    copyRandom(root, cnode,m);
    return cnode;
}
int main() {
    node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->ran = tree->left->right;
    tree->left->left->ran = tree;
    tree->left->right->ran = tree->right;



    cout << "Inorder traversal of original binary tree is: \n";
    printInorder(tree);

    node *clone = cloneTree(tree);

    cout << "\n\nInorder traversal of cloned binary tree is: \n";
    printInorder(clone);
    return 0;
}