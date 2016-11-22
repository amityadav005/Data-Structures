//
// Created by Amit on 11/3/2016.
//

#include<iostream>
#include <cstring>

using namespace std;
int print(int a[], int i, int n, char *s) {
    if(i == n)  {
        cout<<s;
        return 0;
    }

    int ans = 0;
    if(i < n-1 && a[i+1] <= 6 && a[i] <= 2) {
       // char *t = s+(char )(a[i]*10+a[i+1]+'a'-1);
        ans += print(a, i+2, n, t )+1;
    }
    char * v = strcat(s,(char*)(a[i]+'a'-1));
    //char *v = s+(char)(a[i]+'a'-1);
    ans += print(a, i+1, n,v);
    return ans;
}




int main(){

    int a[] = {2,2,4};
    char s[]="";
    //print(a,0,3,s);
    cout<<(char)(a[1]+'a'-1);
}