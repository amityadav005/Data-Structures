#include <iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    int height;
};
int max(int a, int b)
{
    return (a > b)? a : b;
}
node* newNode(int data){
     node* temp = (node*)malloc(sizeof(node));
     temp->data = data;
     temp->left = NULL;
     temp->right = NULL;
     temp->height = 1;
     return temp;
}
int height(node* root){
    if(root=NULL)
        return 0;
    return root->height;
}
int balance(node* root){
    if(root==NULL)
    return 0;
    return height(root->left) - height(root->right);
}
node* leftRotate(node* root){
    node* t1 = root->left;
    node* t2 = t1->right;

    root->left = t2;
    t1->right = root;

    root->height =1+ max(height(root->left), height(root->right));
    t1->height = 1+ max(height(t1->left), height(t1->right));

    return t1;
}
node* rightRotate(node* root){
    node* t1 = root->right;
    node* t2 = t1->left;

    t1->left = root;
    root->right = t2;

    root->height = 1 + max(height(root->left), height(root->right));
    t1->height = 1 + max(height(t1->left), height(t1->right));

    return t1;
}
node* insert(node* root, int data){
    if(root==NULL)
    return newNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);

    if(data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    int bal = balance(root);

    if(bal > 1 && data < root->left->data){
        return rightRotate(root);
    }
    if(bal > 1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal < -1 && data > root->right->data){
        return rightRotate(root);
    }
    if(bal < -1 && data < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        cout<<root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() {
	struct node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */


  preOrder(root);
}
