#include <iostream>
#include<stack>
#include <malloc.h>

using namespace std;
struct myQue{
    stack<int> *s1;
    stack<int> *s2;
};
myQue * createQue(){
    myQue * q  = (myQue*)malloc(sizeof(myQue));
    q->s1 = new stack<int>;
    q->s2 = new stack<int>;
    return q;
}
int push(myQue* q, int val){
    q->s1->push(val);
}
int pop(myQue * q){
    if(q->s1->empty()&&q->s2->empty())
        return -1;

    if(q->s2->empty()){
        while(!q->s1->empty()){
            q->s2->push(q->s1->top());
            q->s1->pop();
        }
    }
    int x = q->s2->top();
    q->s2->pop();
    return x;

}
int main() {
    myQue * q = createQue();

    push(q,10);
    push(q,20);
    int x = pop(q);
    cout<<x;
    return 0;
}