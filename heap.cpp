//
// Created by aamyadav on 3/22/2017.
//

// C++ program to merge k sorted arrays of size n each.
#include<iostream>
#include<limits.h>
#include <stdlib.h>
using namespace std;

#define n 4

struct MinHeapNode
{
    int element;
    int i;
    int j;
};


struct MinHeap
{
    MinHeapNode *harr;
    int heap_size;
};
int left(int i) { return (2*i + 1); }

int right(int i) { return (2*i + 2); }

MinHeapNode getMin( MinHeap * m) { return m->harr[0]; }

void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;  *x = *y;  *y = temp;
}
MinHeap * Create(int size){
    MinHeap * m = (MinHeap *)malloc(sizeof(MinHeap)*size);
    m->heap_size = size;
    m->harr = (MinHeapNode*)malloc(sizeof(MinHeapNode)*size);
    return m;
}
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
}
void MinHeapify(MinHeap* m, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < m->heap_size && m->harr[l].element < m->harr[i].element)
        smallest = l;
    if (r < m->heap_size && m->harr[r].element < m->harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&(m->harr[i]), &(m->harr[smallest]));
        MinHeapify(m, smallest);
    }
}

void replaceMin(MinHeapNode x, MinHeap * m) { m->harr[0] = x; MinHeapify(m,0); }

void buildMinHeap(MinHeap* m, int size)
{

    int i = (size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(m,i);
        i--;
    }
}

int *mergeKArrays(int arr[][n], int k)
{
    int *output = new int[n*k]; // To store output array
    MinHeap *m = Create(k);
    for (int i = 0; i < k; i++)
    {
        m->harr[i].element = arr[i][0]; // Store the first element
        m->harr[i].i = i; // index of array
        m->harr[i].j = 1; // Index of next element to be stored from array
    }
    buildMinHeap(m, k); // Create the heap

    for (int count = 0; count < n*k; count++)
    {
        MinHeapNode root = getMin(m);
        output[count] = root.element;

        if (root.j < n)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
        else root.element = INT_MAX;

        replaceMin(root,m);
    }

    return output;
}



int main()
{
    int arr[][n] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);

    int *output = mergeKArrays(arr, k);

    cout << "Merged array is " << endl;
    printArray(output, n*k);

    return 0;
}
