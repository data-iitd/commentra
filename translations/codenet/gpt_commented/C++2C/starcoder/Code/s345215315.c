#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>
#include<ctype.h>
#include<time.h>
#include<assert.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int h = 19, w = 15;
int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,1,-1};
char s[19][15];
int ans = INT_MAX;

void dfs(int x, int y, int cnt){
    if(cnt > 20) return;
    if(x == h-1){
        ans = min(ans, cnt);
        return;
    }
    rep(i, 8){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(s[nx][ny]!= 'X') continue;
        bool c = true;
        while(c && s[nx][ny] == 'X'){
            s[nx][ny] = '.';
            nx += dx[i];
            ny += dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                if(nx >= h) ans = min(ans, cnt + 1);
                c = false;
            }
        }
        if(c) dfs(nx, ny, cnt + 1);
        while(nx!= x || ny!= y){
            nx -= dx[i];
            ny -= dy[i];
            s[nx][ny] = 'X';
        }
        s[x][y] = '.';
    }
}

int main(void){
    rep(i, h) scanf("%s", s[i]);
    int sx, sy;
    rep(i, h) rep(j, w) if(s[i][j] == 'O'){
        sx = i, sy = j;
        s[i][j] = '.';
    }
    dfs(sx, sy, 0);
    if(ans == INT_MAX) printf("-1\n");
    else printf("%d\n", ans);
}

