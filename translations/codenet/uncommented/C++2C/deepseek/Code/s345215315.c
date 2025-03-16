#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define INF INT_MAX
#define MOD 1000000007

typedef struct {
    int x, y;
} pii;

typedef struct {
    pii data[100];
    int top;
} stack;

void push(stack *s, pii item) {
    s->data[s->top++] = item;
}

pii pop(stack *s) {
    return s->data[--s->top];
}

int is_empty(stack *s) {
    return s->top == 0;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int ans = INF;
int h = 19, w = 15;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char s[19][16];

void dfs(int x, int y, int cnt, stack *st) {
    if (cnt > 20) return;
    if (x == h - 1) {
        ans = fmin(ans, cnt);
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
            push(st, (pii){nx, ny});
            nx += dx[i];
            ny += dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                if (nx >= h) ans = fmin(ans, cnt + 1);
                c = false;
            }
        }
        if (c) dfs(nx, ny, cnt + 1, st);
        while (!is_empty(st) && st->data[st->top - 1].x != nx && st->data[st->top - 1].y != ny) {
            pii p = pop(st);
            s[p.x][p.y] = 'X';
        }
        s[x][y] = '.';
    }
}

int main(void) {
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }
    int sx = -1, sy = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'O') {
                sx = i, sy = j;
                s[i][j] = '.';
            }
        }
    }
    stack st = {.top = 0};
    dfs(sx, sy, 0, &st);
    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);
}
