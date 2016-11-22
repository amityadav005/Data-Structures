#include <iostream>
using namespace std;
int flip(int *arr, int len){
    int sum=0,maxsum=0,num=0;
    int startIndex=0,stopIndex=0,prevIndex=0;
    for(int i=0;i<len;i++){
        if(arr[i] == 1){
            num = -1;
        }else if(arr[i] == 0){
            num = 1;
        }
        sum = sum + num;
        if(maxsum<sum){
            maxsum = sum;
            prevIndex = startIndex;
            stopIndex = i;
        }else if(sum<=0){
            sum = 0;
            startIndex = i+1;
        }
    }
    /*for(int j=prevIndex;j<=stopIndex;j++){
       cout<<arr[j];
    }*/
    cout<<"prevIndex::"<<prevIndex;
    cout<<"stopIndex::"<<stopIndex;
}
int main() {
    int a[] = {1,0,1,0,1,1,0,1,0,0,1};
    int len = sizeof(a)/sizeof(a[0]);
    flip(a,len);
    return 0;
}