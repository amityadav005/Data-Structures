#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void find(char str[], char pat[]){
    int len = strlen(str);
    int plen = strlen(pat);

    int count[256] ={0};
    int pcount[256]={0};

    for (int i = 0; i < plen; i++) {
        pcount[pat[i]]++;
    }

    int start = 0;
    int min =INT_MAX;
    int idx = -1;
    int c=0;
    for (int i = 0; i < len; i++) {
        count[str[i]]++;
        if(pcount[str[i]]!=0&&count[str[i]]<=pcount[str[i]]){
            c++;
        }
        if(c==plen){
            while(count[str[start]]>pcount[str[start]]||pcount[str[start]]==0){
                if(count[str[start]]>pcount[str[start]])
                    count[str[start]]--;
                start++;
            }
            int l  =i-start+1;
            if(min >l){
                min = l;
                idx = start;
            }
        }
    }
    if (idx == -1)
    {
        cout << "No such window exists";
    }
    for (int i = idx; i <=idx+min-1; i++) {
        std::cout<<str[i];
    }

}
int main() {
    char str[] = "this is a test string";
    char pat[] = "tist";
    find(str, pat);
    return 0;
}