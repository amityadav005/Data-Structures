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
    if(*head==NULL){
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
node* reverse(node* head){
    node* cur = head;
    node* prev = NULL;
    node* next;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
node* fold(node* head){
    node* slow= head;
    node* fast = head;
    node* prev;
    while(fast&&fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev ->next=NULL;
    node* head2 = reverse(slow);
    /*// print(head);
    cout<<endl;
    print(head2);*/
    node* res;
    while(head ||head2){
        if(head){
            insert(&res, head->data);
            head = head->next;
        }
        if(head2){
            insert(&res, head2->data);
            head2 =head2->next;
        }
    }
    return res;
}
int main() {
    node* h = NULL;
    insert(&h, 1);
    insert(&h, 2);
    insert(&h, 3);
    insert(&h, 4);
    insert(&h, 5);

    node* f = fold(h);
print(f);
    return 0;
}