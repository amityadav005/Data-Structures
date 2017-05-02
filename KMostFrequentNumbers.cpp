#include <iostream>
#include<map>
#include <stdlib.h>
using namespace std;
struct node{
    int num;
    int freq;
};
struct heap{
    int size;
    node* arr;
    int count;
};
heap* createHeap(int size){
    heap * h =(heap*) malloc(sizeof(heap));
    h->size = size;
    h->arr = (node*)malloc(sizeof(node)*size);
    h->count = 0;
    return h;
}
void swap ( node* a, node* b )
{
    node temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(heap * h, int i){
    int n = h->size;
    int l = 2*i+1;
    int r = 2*i+2;
    int s=i;
    if(l<n&&h->arr[l].freq<h->arr[s].freq)
        s = l;
    if(r<n&&h->arr[r].freq<h->arr[s].freq)
        s =r;
    if(s!=i){
        swap(&h->arr[i], &h->arr[s]);
        heapify(h,s);
    }
}
void buildheap(heap * h){
     int n = h->count-1;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(h, i);
}
void displayMinHeap( heap* minHeap )
{
    int i;
    for( i = 0; i < minHeap->size; ++i )
    {
        cout<<minHeap->arr[i].num<<"::"<<minHeap->arr[i].freq<<endl;
    }
}
int main() {
    int a[] = {5,5,5,5,1,1,1,2,2,2,3,3,3,3,3,3,4,4,4,4};
    int n = sizeof(a)/sizeof(a[0]);
    map <int , int> m;
    int k =3;

    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    heap *h = createHeap(k);
    map<int,int>::iterator it;
    for (it=m.begin(); it!=m.end(); ++it){
        if(h->count < h->size){
            int c = h->count;
            h->arr[c].num = it->first;
            h->arr[c].freq = it->second;
            (h->count)++;
            buildheap(h);
        }
        else if(h->arr[0].freq<it->second){
            h->arr[0].num=it->first;
            h->arr[0].freq=it->second;
            heapify(h,0);
        }
    }
    displayMinHeap(h);
    return 0;
}