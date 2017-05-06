#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* newNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
}
void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
node* merge(node* h1, node* h2){
    node* res =newNode(5);
    node* cur = res;
    while(h1||h2){
        if(h1==NULL){
            cur->next = h2;
            return res->next;
        }
        if(h2==NULL){
            cur->next = h1;
            return res->next;
        }if(h1->data<h2->data){
            cur->next = newNode(h1->data);
            h1 = h1->next;
            cur = cur->next;
        }
        else{
            cur->next = newNode(h2->data);
            h2 = h2->next;
            cur = cur->next;
        }


    }
    return res->next;
}
int main() {
    node* list1 = newNode(10);
    list1->next = newNode(20);
    list1->next->next = newNode(30);

    node* list2 = newNode(22);
    list2->next = newNode(25);
    list2->next->next = newNode(35);
    list2->next->next->next = newNode(55);

    node * res = merge(list1, list2);
    print(res);
    return 0;
}