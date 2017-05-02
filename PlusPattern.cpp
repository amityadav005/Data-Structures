#include <iostream>
using namespace std;
int isvalid(int r, int l,int t, int b){
    if(r>=0&&r<=4
       &&l>=0&&l<=4
       &&t>=0&&t<=4
       &&b>=0&&b<=4)
        return 1;
    return 0;
}
int main() {
    int a[5][5]={
            {0,1,1,0,0},
            {1,1,1,0,0},
            {1,1,1,1,0},
            {0,0,1,0,0},
            {0,0,1,0,0}
    };


    int r,l,t,b,count;
    bool flag;
    int max = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(a[i][j]==1){
                count=0;
                flag = true;
                r=j+1;
                l=j-1;
                t=i-1;
                b=i+1;
                while(flag&&isvalid(r,l,t,b)){
                    if(a[i][l]==1&&a[i][r]==1&&a[t][j]==1&&a[b][j]==1){
                        count++;
                        r++;l--;t++;b--;

                    }else{
                        flag = false;
                    }
                }
                if(count>max)
                    max = count;
            }
        }
    }

    cout<<"count"<<max;
    return 0;
}//
// Created by Amit on 2/25/2017.
//

