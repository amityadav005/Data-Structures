//
// Created by Amit on 11/16/2016.
//
#include <iostream>
#include <stack>
using namespace std;
void getMin(){
    stack<int> s1;
    stack<int> s2;


    while(1){
    int x;
    cout<<"enter the ext number:";
    cin>>x;

    int k =3;
        if(s1.size()<k){
            while(s1.top()>x){
                int t = s1.top();
                s1.pop();
                s2.push(t);
            }
            s1.push(x);
            while(!s2.empty()){
                int t = s2.top();
                s2.pop();
                s1.push(t);
            }

        }else if(s1.size()==k){
            while(s1.top()>x){
                int t = s1.top();
                s1.pop();
                s2.push(t);
            }s1.push(x);
            while(!s2.empty()){
                int t = s2.top();
                s2.pop();
                s1.push(t);
            }
            s1.pop();

        }
        int n = s1.top();
        cout<<"number is:::"<<n<<endl;
        cout<<"size"<<s1.size()<<endl;
    }

}

int main(){
    getMin();
}

