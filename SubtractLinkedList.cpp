#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;
struct node{
    int data;
    node* next;
};
node* newNode(int data){
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(node** head, int data){
    if(*head ==NULL){
        *head = newNode(data);
        return;
    }
    node* ptr = *head;
    while(ptr->next){
        ptr= ptr->next;
    }
    ptr->next = newNode(data);
}
int getLength(node* head){
    int count= 0 ;
    while(head){
        count++;
        head= head->next;
    }
    return count;
}
void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head= head->next;
    }
}
node* addsameSize(node* head, node* head2, int * carry){
    if(head==NULL)
        return NULL;
    node* t = (node*)malloc(sizeof(node));
    t->next = addsameSize(head->next, head2->next, carry);
    int d = head->data;
    int d2 = head2->data;
    if(*carry)
        d= d-1;
    if(d<d2){
        *carry = 1;
        d = d+10;
    }
    t->data =(d-d2);
    return t;
}
node* add(node* head, node* head2){
    int l1 = getLength(head);
    int l2 = getLength(head2);
    node* first = head;
    node* sec = head2;
    node* lnode= head;
    node* snode=head2;

    if(l1==l2){
        while(first){
            if(first->data<sec->data){
                lnode = sec;
                snode = first;
                break;
            }else{
                first = first->next;
                sec = sec->next;}
        }
    }else if(l2>l1){
        lnode = sec;
        snode = first;
    }
    int d = abs(l1-l2);
    for(int i = 0;i<d;i++){
        node* n = newNode(0);
        n->next = snode;
        snode = n;
    }
    int carry = 0;

    node* res  = addsameSize(lnode, snode,&carry);

    return res;

}
int main() {
    node* h=NULL;
    insert(&h, 0);
    insert(&h, 2);
    insert(&h, 3);
    node* h2 =NULL;
    insert(&h2, 1);
    insert(&h2, 0);
    insert(&h2, 3);
    node* res = add(h,h2);
    print(res);
    return 0;
}