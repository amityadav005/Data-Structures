#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;
struct QNode
{
    int key;
    struct QNode *next;
};
struct Queue
{ int size;
    struct QNode *front, *rear;
};
struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}
void enQueue(struct Queue *q, int k)
{q->size++;
    struct QNode *temp = newNode(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;

}
struct QNode *deQueue(struct Queue *q)
{
    if (q->front == NULL)
        return NULL;
    q->size--;
    struct QNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}
struct stack{
    Queue * q;
};
void push(stack* s,int val)
{
    int sz = s->q->size;
    enQueue(s->q,val);
    for (int i=0; i<sz; i++)
    {
        enQueue(s->q,deQueue(s->q)->key);
    }
}
int pop(stack * s)
{
    if (s->q->size==0)
        cout << "No elements\n";
    else
        return deQueue(s->q)->key;
}
// Driver Program to test anove functions
int main()
{
    struct Queue *q = createQueue();

    stack * s= (stack*)malloc(sizeof(stack));
    s->q = q;
    push(s,10);
    push(s,20);
    push(s,30);
    cout<<"popped::";
    cout<<pop(s);
    cout<<endl;
    cout<<"top::";
    cout<<s->q->front->key;
}
