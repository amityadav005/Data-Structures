#include <iostream>
#include <malloc.h>
#include<map>
using namespace std;
struct node{
    int data;
    node* next;
    node* ran;
};
node* newNode(int data){
    node* temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->ran  =NULL;
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
        cout<<"Data:: "<<head->data<<"  Ran ::"<<head->ran->data<<endl;
        head= head->next;
    }
}

node* clone(node* head){
    map<node* ,node* > m;

    node* ptr = head;
    while( ptr){
        m[ptr] = newNode(ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    node* ptr2=NULL;
    while(ptr){
        ptr2 = m[ptr];
        ptr2->next = m[ptr->next];
        ptr2->ran = m[ptr->ran];
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    return  m[head];
}
int main() {
    node* h=NULL;
    insert(&h, 1);
    insert(&h, 2);
    insert(&h, 3);
    insert(&h, 4);

    h->ran = h->next->next;
    h->next->ran = h->next->next->next;
    h->next ->next->ran = h->next;
    h->next->next->next->ran = h;
    node* cl=clone(h);
    print(h);
    cout<<"cloned:::"<<endl;
    print(cl);
    return 0;
}