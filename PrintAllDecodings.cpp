
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


void countDecoding(string digits, int n, string str)
{

    if (n == 0){
        cout<<str<<endl;

    }


        char c = digits.at(0);

        str.push_back('A'+c-1);
        countDecoding(digits.substr(1), n-1,str);


    if(n>1){

            const char * c = (digits.substr(0,2)).c_str();
            str.push_back('A'+atoi(c)-1);
            countDecoding(digits.substr(2), n-2,str);
        }

}


int main()
{
    string digits= "121";
    int n = digits.length();
     countDecoding(digits, n,"");
    //cout<<digits.at(2);
   /* string s ="";
    s.push_back('a');
    s.push_back('b'-1);
    cout<<s;*/

    return 0;
}
