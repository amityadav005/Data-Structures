#include <iostream>
#include<queue>
#include <stdlib.h>
using namespace std;
struct point{
    int x;
    int y;
};
point* newpoint(int i, int j){
    point * p = (point*)malloc(sizeof(point));
    p->x = i;
    p->y=j;
    return p;
}
bool isvalid(int x, int y, bool v[3][3]){
    if(x>=0&&x<3&&y>=0&&y<3&&v[x][y]==false)
        return true;
    return false;
}
void BFS(int m[3][3],int i,int j){
    queue<point*> q;

    bool v[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            v[i][j] = false;
        }
    }
    int x[]= {0,1,0,-1};
    int y[]= {1,0,-1,0};
    point * p = newpoint(i, j);
    v[0][0] = true;
    q.push(p);
    int len = 0;
    int min = -1;
    while(q.size()>0){
        len++;
        int size = q.size();
        while(size>0){
            p = q.front();
            q.pop();
            v[p->x][p->y]= true;
            cout<<m[p->x][p->y]<<" ";
            for(int k = 0;k<4;k++){
                if(m[p->x+x[k]][p->y+y[k]]==9)
                    min = len;
                if(isvalid(p->x+x[k],p->y+y[k],v))
                {
                    v[p->x+x[k]][p->y+y[k]]= true;
                    p = newpoint(p->x+x[k],p->y+y[k]);
                    q.push(p);
                }
            }
            size--;
        }
    }
    //cout<<"len"<<len;
}
int main() {
    int m[3][3]={
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    BFS(m,0,0);
    return 0;
}