#include <iostream>
#include <stdlib.h>
#include<map>
using namespace std;

struct node{
    int num;
    int freq;
    int index;
};
map <int , node*> m ;
node* newNode(int num){
    node* temp = (node*)malloc(sizeof(node));
    temp->num = num;
    temp->freq =0;
    temp->index = -1;
    return temp;
}
struct heap{
    int size;
    int count;
    node* arr;
};
heap * createHeap(int k){
    heap* h = (heap*)malloc(sizeof(heap));
    h->count = 0;
    h->size = k;
    h->arr = (node*)malloc(sizeof(node)*k);
    return h;
}
void swap ( node* a, node* b )
{
    node temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(heap *minHeap, int idx){
    int left, right, smallest;

    left = 2 * idx + 1;
    right = 2 * idx + 2;
    smallest = idx;
    if ( left < minHeap->count &&
         minHeap->arr[ left ]. freq <
         minHeap->arr[ smallest ]. freq
            )
        smallest = left;

    if ( right < minHeap->count &&
         minHeap->arr[ right ]. freq <
         minHeap->arr[ smallest ]. freq
            )
        smallest = right;
    if( smallest != idx )
    {
        minHeap->arr[ smallest ].index = idx;
        m[minHeap->arr[ smallest ].num]->index = idx;

        m[minHeap->arr[idx].num]->index = smallest;

        minHeap->arr[idx].index = smallest;
        swap(&minHeap->arr[ smallest ], &minHeap->arr[ idx ]);
        heapify( minHeap, smallest );
    }
}
void buildHeap(heap * h){
    int n = h->count;
    for (int i = (n-1)/2; i >=0; i--) {
        heapify(h,i);
    }
}
void kfreuent(map <int, node*> &m, heap * h, int item){
    node *nod = m[item];
    if(!nod)
        nod = newNode(item);

    (nod->freq)++;
    m[item] = nod;
    if(nod->index!=-1){
        (h->arr[nod->index].freq)++;
        heapify(h, nod->index);
    }
    else if(h->count<h->size){
        int c = h->count;
        h->arr[c].num= item;
        h->arr[c].freq = 1;
        h->arr[c].index = c;
        nod->index = c;
        m[item] = nod;
        (h->count)++;
       buildHeap(h);
    }
    else if(h->arr[0].freq< nod->freq){
        m[h->arr[0].num]->index = -1;

        h->arr[0].num = item;
        h->arr[0]. freq = nod->freq;
        h->arr[0]. index = 0;
        nod->index = 0;
        m[item] = nod;
        heapify(h, 0);
    }

}
void display(heap *h){
    for (int i = 0; i < h->count; i++) {
        cout<<"Num   "<<h->arr[i].num<<"  Freq  "<<h->arr[i].freq<<endl;

    }
    cout<<"------------------------"<<endl;
}
int main() {

    int k = 3;
    heap *h = createHeap(k);

    int a[] = {5,5,5,2,2,2,2,2,4,4,4,4,3,3,3,3,3,3,5,5,5,5,1,1,1,1,1,1,1,1,1};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        kfreuent(m,h,a[i]);
        display(h);
    }

    return 0;
}