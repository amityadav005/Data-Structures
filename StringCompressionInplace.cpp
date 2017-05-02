#include <iostream>

using namespace std;
void runLength(string str){
    int len = str.length();
    int index = 0;
    for (int i = 0; i < len; i++) {
        int count = 1;
        int j = i+1;
        while(str[i]==str[j]){
            i++;j++;
            count++;
        }
        str[index++] = str[i];
        if(count>1){
            string temp = std:to_string(count);
            for(auto c:temp)
                str[index++] = c;

        }
    }
    str.resize(index);
    cout<<str;
}
int main() {
    string str  = "abcccccddd";
    runLength(str);
    return 0;
}