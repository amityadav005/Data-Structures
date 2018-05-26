#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* newNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void print(node * head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}
node* reverse(node* head, int k){
    stack<node*> stack;
    node * cur = head;
    node* prev=NULL;
    while(cur){
        int c=0;
        while(cur && c<k){
            stack.push(cur);
            cur = cur->next;
            c++;
        }

        while(stack.size()>0){
            if(!prev){
                prev=stack.top();
                head = prev;
                stack.pop();
            }else{
                prev->next = stack.top();
                prev = prev->next;
                stack.pop();
            }
        }
    }
    prev ->next = NULL;
    return head;
}

int main() {
    node* head;
    head = newNode(10);
    head->next= newNode(20);
    head->next->next= newNode(30);
    head->next->next->next= newNode(40);
    head->next->next->next->next= newNode(50);
    print(head);
    cout<<endl;
    head =reverse(head,3);
    print(head);
    cout<<endl;
    print(head);
    return 0;
}//
// Created by Amit on 5/26/2018.
//

