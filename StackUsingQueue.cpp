#include <iostream>
#include<queue>
#include <malloc.h>

using namespace std;
struct myStack {
    queue<int> *q;
};

myStack * createStack(){
    myStack *s =   (myStack *)malloc(sizeof(myStack));
    s->q = new queue<int>;
    return s;
}
int push(int data, myStack *s){

    int size = s->q->size();
    s->q->push(data);
    for (int i=0; i<size; i++)
    {
        s->q->push(s->q->front());
        s->q->pop();
    }
}
void pop(myStack *s)
{
    if (s->q->empty())
        cout << "No elements\n";
    else
        s->q->pop();
}
int main() {
    myStack *s  =createStack();
    push(12, s);
    push(14, s);
    pop(s);

    cout<<(s->q)->front();
    return 0;
}