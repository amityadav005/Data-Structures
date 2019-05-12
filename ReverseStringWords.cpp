#include <iostream>
#include<cstring>
using namespace std;

void reverse(string str){
    string ans = "";
    string temp = "";
    
    int l = str.length();
    int i = 0;
    while(i<l){
    temp = "";   
        while(i<l && str[i]!=' '){
            temp  = temp + str[i];
            i++;
        }
            ans = temp+ans;
        if(i<l){
            ans = str[i] + ans ;
            i++;
        }
    }
    cout<< ans;
    
    
}

int main() {
    string str = "this is a string";
    reverse(str);
	return 0;
}
