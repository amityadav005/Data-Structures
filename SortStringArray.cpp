#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int comp(const void* a, const void* b)
{
    int i=0;
    while(*(char*)a+i&&*(char*)b+i){
        if(*(char*)a+i==32||*(char*)a+i>*(char*)b+i)
            return 1;
        else if(*(char*)b+i||*(char*)b+i>*(char*)a+i)
            return -1;
        i++;
    }
    if(*(char*)a+i)
        return 1;
    else if(*(char*)b+i)
        return -1;
}
int compr(char a[], char b[])
{
    int i=0;
    while(*(a+i)&&*(b+i)){
        if(*(a+i)==32||*(a+i)>*(b+i))
            return 1;
        else if(*(b+i)==32||*(b+i)>*(a+i))
            return -1;
        i++;
    }
    if(*(a+i))
        return 1;
    else if(*(b+i))
        return -1;

    return 0;
}


int main()
{
    string str[] = {"nun","NUN","mun"};
    string temp;


    for(int i = 0; i < 2; ++i)
       for( int j = i+1; j < 3; ++j)
       {
           char a[20];
           strcpy(a,str[i].c_str());
           char b[20];
           strcpy(b,str[j].c_str());
          if(compr(a, b)>0)
          {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
          }
    }
    //qsort(str,10, sizeof(char),comp);


    char a[] = "fun";
    char b[] = "nun";
    int res = compr(a,b);
   // cout<<res;

    cout << "In lexicographical order: " << endl;

     for(int i = 0; i < 3; ++i)
     {
        cout << str[i] << endl;
     }
    return 0;
}