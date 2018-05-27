#include <iostream>
#include <malloc.h>

using namespace std;
struct node{
    int data; 
    node* next;
};
void newNode(node** head,int data){
    node* temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    node* cur = *head;
    if(*head==NULL){
        *head = temp;
        return;
    }else{
        while(cur->next)
        cur = cur->next;
    }
    cur->next = temp;
}
void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
void deleteList(node** h){
    node* head = *h;
    if(!head)
    return;
    deleteList(&head->next);
    head->next=NULL;
    free(head);
    *h=NULL;
}
int main() {
    node* head=NULL;
    newNode(&head,10);
    newNode(&head,20);
    newNode(&head,30);
    newNode(&head,40);
    newNode(&head,50);
    print(head);
    deleteList(&head);
    cout<<endl;
    print(head);
    
	return 0;
}