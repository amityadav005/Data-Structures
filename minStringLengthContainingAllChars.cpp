#include<stdio.h>
#include<string.h>
#define MAX 256
void fun(char *str1,char* str2){
    int i=0;
    int count[MAX]={0};
    bool sub[MAX];
    while(str2[i]){
        ++count[str2[i]];
        sub[str2[i]]=true;
        i++;
    }
    i=0;
    int l=0,r=0,k=0;
    int count1[MAX]={0};
    while(str1[i]){
        if(k==strlen(str2))
            break;
        if(count[str1[i]]){
            count[str1[i]]--;
            ++k;
        }
        if(sub[str1[i]])
            count1[str1[i]]++;
        i++;
    }
    r=i-1;
    int j=0,m=r-l+1;
    while(str2[j]){
        ++count[str2[j]];
        j++;
    }
    j=0;
    while(!count[str1[j]])
        j++;
    while(str1[i]){
        if(count[str1[i]])
            ++count1[str1[i]];
        if(str1[i]==str1[j]){
            while(1){
                if(count[str1[j]]&&count1[str1[j]]==count[str1[j]]){
                    if(i-j+1<m){
                        m=i-j+1;
                        l=j;
                        r=i;
                    }
                    break;
                }
                if(count[str1[j]]&&count1[str1[j]]>count[str1[j]]){
                    count1[str1[j]]--;
                    j++;
                }
                if(!count[str1[j]])
                    j++;
            }
        }
        i++;
    }
    for(i=l;i<=r;i++)
        printf("%c",str1[i]);
}
int main(){
    char str1[]="his is a test string";
    char str2[]="tist";
    fun(str1,str2);
    return 0;
}