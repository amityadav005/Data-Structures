#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    int  a[]= {5,4,6,18,7};
    int n = sizeof(a)/sizeof(a[0]);
    int last =n-1;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {

        int r = rand()%(last+1);

        cout<<a[r]<<" ";
        int t=a[last];
        a[last] = a[r];
        a[r] = t;
        last--;
    }
    return 0;
}