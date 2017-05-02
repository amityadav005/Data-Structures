#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void greate(char str[]){
    int n  = strlen(str);
    cout<<n<<endl;
    int i;
    for (int i = n-2; i>=0; i--) {
        cout<<str[i]<<endl;
        if(str[i] < str[i+1])
            break;
    }
    cout<<i<<endl;
    if(1==-1){
        cout<<"not possible";
        return;
    }
    int idx = i+1;
    int j;
    for ( j = i+1; j <n; j++) {
        if(str[j]>str[i]&&str[j]<str[idx])
            idx = j;
    }
    char t = str[i];
    str[i] = str[idx];
    str[idx] = t;

    sort(str+i,str+n);
    cout<<str;
}
int main() {
    char  str[] = "94651";
    greate(str);
    return 0;
}//
// Created by aamyadav on 3/23/2017.
//

