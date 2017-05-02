#include<bits/stdc++.h>


using namespace std;


int main()
{

    string str,temp,ans;
    str = "this is my name";
    int l=str.length();

    for(int i=0;i<l;i++){
        temp="";
        while(str[i]!=' ' && i<l){
            temp+=str[i];
            i++;
        }
        ans = temp + ans;
        if(i<l)
            ans = str[i] + ans;

    }
    cout<<ans;


    return 0;
}