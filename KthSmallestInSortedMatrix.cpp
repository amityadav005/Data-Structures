#include <iostream>
#include <malloc.h>
#include<climits>
using namespace std;
struct node{
    int ele;
    int i;
    int j;
};
struct heap{
    node * arr;
    int count;
    int size;
};
heap * createHeap(int size){
    heap *h = (heap*)malloc(sizeof(heap));
    h->size = size;
    h->count = 0;
    h->arr = (node*)malloc(sizeof(node)*size);
}
void heapify(heap * h, int i){
    int n = h->count;
    int l = (i*2)+1;
    int r = (i*2)+2;
    int s = i;
    if(l<n&&h->arr[l].ele<h->arr[s].ele){
        s = l;
    }
    if(r<n&&h->arr[r].ele<h->arr[s].ele){
        s = r;
    }
    if(s!= i){
        node t = h->arr[s];
        h->arr[s] = h->arr[i];
        h->arr[i] = t;
        heapify(h,s);
    }

}
void buildHeap(heap* h){
    int n = h->count;
    for (int i = (n-1)/2; i >=0 ; i--) {
        heapify(h,i);
    }
}

int find(int m[4][4], int k){
    heap* h  = createHeap(4);
    for (int i = 0; i < 4; i++) {
        h->arr[i].ele = m[0][i];
        h->arr[i].i = 0;
        h->arr[i].j = i;
        h->count++;
    }

    buildHeap(h);
    int c = 0;
    node t;
    while(c<k){
        c++;
        t = h->arr[0];

        int next = t.i<3?m[(t.i)+1][t.j]:INT_MAX;

        h->arr[0].ele = next;
        h->arr[0].i =(t.i)+1;
        h->arr[0].j = t.j;
        heapify(h,0);
    }

    return t.ele;
}
int main() {
    int m[4][4] = {
            {10, 20, 30, 40},
            {15, 25, 35, 45},
            {25, 29, 37, 48},
            {32, 33, 39, 50},

    };

    cout<<find(m,15);
    return 0;
}