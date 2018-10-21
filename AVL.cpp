#include <iostream>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
    int height;
};
int max(int a, int b)
{
    return (a > b)? a : b;
}
Node* newNode(int key){
     Node* temp = (Node*)malloc(sizeof(Node));
     temp->key = key;
     temp->left = NULL;
     temp->right = NULL;
     temp->height = 1;
     return temp;
}
int height(Node* root){
    if(root==NULL)
        return 0;
    return root->height;
}
int balance(Node* root){
    if(root==NULL)
    return 0;
    return height(root->left) - height(root->right);
}
Node* leftRotate(Node* root){
    Node* t1 = root->left;
    Node* t2 = t1->right;

    root->left = t2;
    t1->right = root;

    root->height =1+ max(height(root->left), height(root->right));
    t1->height = 1+ max(height(t1->left), height(t1->right));

    return t1;
}
Node* rightRotate(Node* root){
    Node* t1 = root->right;
    Node* t2 = t1->left;

    t1->left = root;
    root->right = t2;

    root->height = 1 + max(height(root->left), height(root->right));
    t1->height = 1 + max(height(t1->left), height(t1->right));

    return t1;
}
Node* insert(Node* root, int key){
    if(root==NULL)
    return newNode(key);

    if(key < root->key)
        root->left = insert(root->left, key);

    if(key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    int bal = balance(root);

    if(bal > 1 && key < root->left->key){
        return rightRotate(root);
    }
    if(bal > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal < -1 && key > root->right->key){
        return rightRotate(root);
    }
    if(bal < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() {
	struct Node *root = NULL;

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
