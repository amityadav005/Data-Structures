#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
node* newNode(int data){
    node* temp  = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left=temp->right =NULL;
    return temp;
}

node* lca(node* root, int n1, int n2, bool *v1, bool *v2){
    if(root==NULL)
        return NULL;
    if(root->data==n1){
        *v1 = true;
        return root;
    }
    if(root->data==n2){
        *v2 = true;
        return root;
    }
    node* leftlca = lca(root->left,n1,n2,v1,v2);
    node* rightlca = lca(root->right,n1,n2,v1,v2);
    if(leftlca&&rightlca)
        return root;

    if(leftlca)
        return leftlca;
    else
        return rightlca;

}
int find(node* root, int n){
    if(root==NULL)
        return false;
    if(root->data==n||find(root->left,n)||find(root->right,n))
        return true;

    return false;

}

node* findLca(node* root, int n1,int n2){
    bool v1 =false;
    bool v2 =false;
    node* l = lca(root,n1,n2,&v1,&v2);

    if (v1 && v2 || v1 && find(l, n2) || v2 && find(l, n1))
        return l;

    return NULL;
}
int dist(node* root, int d){
    if(root==NULL)
        return 0;
    if(root->data==d)
        return 0;
    int dl = dist(root->left,d);
    if(dl)
        return dl+1;
    int dr =dist(root->right,d);
    if(dr)
        return dr+1;

    return -1;
}
int main() {
    node* root = newNode(30);

    root->left = newNode(20);
    root->right = newNode(40);
    root->left->left = newNode(15);
    root->left->right = newNode(25);
    root->right->left = newNode(35);
    root->right->right = newNode(45);
    node* lc = findLca(root,35,15);
    std::cout<< lc->data << std::endl;

    cout<<dist(lc,35);
    return 0;
}