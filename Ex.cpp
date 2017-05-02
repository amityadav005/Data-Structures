// C++ program to implement a stack using
// single queue
#include<bits/stdc++.h>
using namespace std;

// User defined stack that uses a queue
struct Stack
{
    queue<int>q;

};

// Push operation
void push(int val, Stack *s)
{
    // Get previous size of queue
    int si = s->q.size();

    // Push current element
    s->q.push(val);

    // Pop (or Dequeue) all previous
    // elements and put them after current
    // element
    for (int i=0; i<si; i++)
    {
        // this will add front element into
        // rear of queue
        s->q.push(s->q.front());

        // this will delete front element
        s->q.pop();
    }
}

// Removes the top element
void pop(Stack *s)
{
    if (s->q.empty())
        cout << "No elements\n";
    else
        s->q.pop();
}

// Returns top of stack
int top(Stack *s)
{
    return (s->q.empty())? -1 : s->q.front();
}

// Returns true if Stack is empty else false
bool empty(Stack *s)
{
    return (s->q.empty());
}

// Driver code
int main()
{
    Stack * s;
    push(10,s);
    s.push(20,s);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    s.pop();
    cout << s.top() << endl;
    return 0;
}
