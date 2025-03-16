
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<set>
#include<map>
#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int H = 19;
const int W = 15;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,1,-1};

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

int ans = 1000000000;
int h = 19,w = 15;
char s[H][W+1];

void dfs(int x, int y, int cnt){
    if(cnt > 20)return;
    //cout << x << " " << y << " " << cnt << endl;
    //rep(i,h)cout << s[i]<<endl;
    if(x == h-1){
        ans = min(ans,cnt);
        return;
    }
    rep(i,8){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
        if(s[nx][ny]!= 'X')continue;
        bool c = true;
        while(c && s[nx][ny] == 'X'){
            s[nx][ny] = '.';
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                if(nx >= h)ans = min(ans, cnt+1);
                c = false;
            }
        }
        if(c)dfs(nx,ny,cnt+1);
        while(nx!= x || ny!= y){
            nx -= dx[i];
            ny -= dy[i];
            s[nx][ny] = 'X';
        }
        s[x][y] = '.';
    }
}

int main(void){
    rep(i,h)scanf("%s",s[i]);
    int sx,sy;
    rep(i,h)rep(j,w)if(s[i][j] == 'O'){
        sx = i, sy = j;
        s[i][j] = '.';
    }
    dfs(sx,sy,0);
    if(ans == 1000000000)cout << -1 << endl;
    else cout << ans << endl;
}
