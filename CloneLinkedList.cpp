//
// Created by Amit on 11/22/2016.
//
#include <iostream>
#include <malloc.h>

using namespace std;
struct Node{
    int data ;
    Node* next;
};
Node * newNode(int data){
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->data =data;
    temp->next=NULL;
    return temp;
}
Node* insert(Node* h,Node * node){
    Node* head = h;
    if(head==NULL){
        head=node;
        return head;
    }
    while(head->next!=NULL){
        head= head->next;
    }
    head->next = node;
    return h;
}
Node * clone(Node* h){
    Node * head = h;
    if(head==NULL)
        return NULL;
    Node* c=NULL;
    while(head!=NULL){
        Node * node = newNode(head->data);
        head = head->next;
        c = insert(c, node);
    }
    return c;
}
void printList(Node * head){
    Node * h = head;
    if(head==NULL)
        return;
    while(head!=NULL){
        cout<<head->data<<" ";
        head  =head->next;
    }
}
int main() {
    Node * head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    // printList(head);
    Node* c = clone(head);
    printList(head);
    cout<<"Clone:::";
    printList(c);
    return 0;
}
