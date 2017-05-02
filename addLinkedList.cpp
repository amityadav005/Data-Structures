#include <iostream>
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
void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head= head->next;
    }
}
int  getLength(node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}
node* addSamesize(node* head, node* head2, int * carry){
    if(head==NULL)
        return NULL;
    node* temp = (node*)malloc(sizeof(node));
    temp->next = addSamesize(head->next, head2->next, carry);
    int sum = head->data+head2->data+*carry;
    temp->data = sum%10;
    *carry =sum/10;
    return temp;
}
void addCarry(node* cur, node* head,int* carry,node** res){
    if(cur==NULL)
        return;
    while(cur!=head){
        addCarry(head->next, cur,carry ,res);
        int sum = cur->data+*carry;
        node* t = newNode(sum%10);

        *carry = sum/10;
        t->next = *res;
        *res = t;

    }
}
node* add(node* head, node* head2){
    int l1 =getLength(head);
    int l2 = getLength(head2);
    node* res;
    int carry = 0;
    if(l1==l2){
        res = addSamesize(head, head2, &carry);
    }else{
        if(l2>l1){
            node * t = head2;
            head2 = head;
            head = t;
        }
        node* cur;
        int d = abs(l1-l2);
        for(cur= head;d--; cur= cur->next);

        res = addSamesize(cur->next, head2, &carry);

        addCarry(head, cur, &carry, &res);


    }
    if(carry){
        node* t = newNode(carry);
        t->next = res;
        res = t;
    }
    return res;
}
int main() {
    node* h=NULL;
    insert(&h, 1);
    insert(&h, 2);
    insert(&h, 3);
    node* h2 = NULL;
    insert(&h2, 1);
    insert(&h2, 2);
    insert(&h2, 3);
    node* res = add(h,h2);

    print(res);

    return 0;
}