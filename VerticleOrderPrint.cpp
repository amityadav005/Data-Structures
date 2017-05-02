#include <iostream>
#include <malloc.h>
using namespace std;
struct node{
    int data;
    node* next;
};
struct dnode{
    dnode *left;
    dnode*right;
    node* list;
};
struct tnode{
    int d;
    tnode* l;
    tnode * r;

};
node* newNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(dnode * d,int data){
    node* t = newNode(data);
    t->next=d->list;
    d->list = t;

}
dnode * newdNode(){
    dnode* t = (dnode*)malloc(sizeof(dnode));
    t->list =NULL;
    t->left = NULL;
    t->right = NULL;
    return t;
}
tnode* newTnode(int data){
    tnode * t = (tnode*)malloc(sizeof(tnode));
    t->d = data;
    t->l=NULL;
    t->r=NULL;
    return t;
}
void verticle(tnode* root, dnode* dl){
    if(root){
        insert(dl,root->d);
    }
    if(root->l){
        if(dl->left==NULL)
            dl->left = newdNode();
        verticle(root->l, dl->left);
    }
    if(root->r){
        if(dl->right==NULL)
            dl->right = newdNode();
        verticle(root->r, dl->right);
    }
}
int main() {
    tnode * root = newTnode(1);
    root->l = newTnode(2);
    root->r = newTnode(3);
    root->l->l = newTnode(4);
    root->l->r = newTnode(5);
    root->r->l = newTnode(6);
    root->r->r = newTnode(7);
    dnode* dl = newdNode();
    verticle(root, dl);

    /*while(dl->left!=NULL)
    dl = dl->left;*/
    node* t = dl->list;
    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }
    //cout<<dl->left->left->list->data;
    return 0;
}