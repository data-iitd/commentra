
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<set>
#include<map>
#define re register
#define ll long long
using namespace std;
inline int gi(){
    re int f=1,sum=0;
    re char ch=getchar();
    while(ch>'9'|| ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        sum=(sum<<3)+(sum<<1)+ch-'0';
        ch=getchar();
    }
    return sum*f;
}
const int N=20,inf=0x3f3f3f3f;
int n,m,ans=inf,dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};
char s[N][N];
struct node{
    int x,y,step;
};
queue<node>q;
inline bool check(int x,int y){
    if(x<1||x>n||y<1||y>m)return 0;
    return s[x][y]!='X';
}
inline void bfs(){
    while(!q.empty()){
        node now=q.front();q.pop();
        if(now.x==n){ans=min(ans,now.step);return;}
        for(re int i=0;i<9;++i){
            int tx=now.x,ty=now.y;
            while(check(tx,ty)){
                s[tx][ty]='.';
                tx+=dx[i],ty+=dy[i];
            }
            if(tx>n){ans=min(ans,now.step+1);continue;}
            q.push((node){tx,ty,now.step+1});
            tx=now.x,ty=now.y;
            while(tx!=now.x||ty!=now.y){
                tx-=dx[i],ty-=dy[i];
                s[tx][ty]='X';
            }
        }
    }
}
int main(){
    n=19,m=15;
    for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(re int i=1;i<=n;++i)
        for(re int j=1;j<=m;++j)
            if(s[i][j]=='O'){
                s[i][j]='.';
                q.push((node){i,j,0});
            }
    bfs();
    if(ans==inf)puts("-1");
    else printf("%d\n",ans);
    return 0;
}
