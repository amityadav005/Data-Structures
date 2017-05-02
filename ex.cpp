#include <iostream>
#include <limits.h>

using namespace std;

int main() {
int a[] = {1,1,1,1,0,1,0,0,1,0,1,1,0,1,1,1};
	
	
	int n = sizeof(a)/sizeof(a[0]);
	int k =3;
	int min = INT_MAX;
	int count=0;
	int i = 0;
	while(i<n&&a[i]==1)
	i++;
	if(i==n)
	cout<<"no zero";
	int start = i;
	for (; i < n; i++) {
	    if(a[i]==1)
	    continue;
	    if(a[i]==0)
	    count++;
	    if(count ==k){
	        if(min>(i-start+1))
	        min = i-start+1;
            start++;
            while(a[start]==1)
                start++;
	    }

	}
	cout<<min;
	return 0;
}