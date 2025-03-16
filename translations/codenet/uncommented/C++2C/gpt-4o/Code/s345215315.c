#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
<<<<<<< HEAD
#include <limits.h>

#define ll long long
#define INF 1000000000
#define MAX_H 19
#define MAX_W 15

int ans = INF;
int h = MAX_H, w = MAX_W;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char s[MAX_H][MAX_W + 1]; // +1 for null terminator
=======

#define ll long long
#define INF 1e9
#define h 19
#define w 15

int ans = INF;
char s[19][16]; // 15 characters + 1 for null terminator
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
>>>>>>> 98c87cb78a (data updated)

void dfs(int x, int y, int cnt) {
    if (cnt > 20) return;
    if (x == h - 1) {
        ans = (cnt < ans) ? cnt : ans;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (s[nx][ny] != 'X') continue;
        bool c = true;
        while (c && s[nx][ny] == 'X') {
            s[nx][ny] = '.';
            nx += dx[i];
            ny += dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                if (nx >= h) ans = (cnt + 1 < ans) ? cnt + 1 : ans;
                c = false;
            }
        }
        if (c) dfs(nx, ny, cnt + 1);
        while (nx != x || ny != y) {
            nx -= dx[i];
            ny -= dy[i];
            s[nx][ny] = 'X';
        }
        s[x][y] = '.';
    }
}

int main(void) {
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }
    int sx, sy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'O') {
                sx = i;
                sy = j;
                s[i][j] = '.';
            }
        }
    }
    dfs(sx, sy, 0);
    if (ans == INF) printf("-1\n");
    else printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
