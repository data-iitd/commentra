#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 100005

int n, m;
int vis[MAXN], ci = 0, cb = 0, cc = 0;
int g[MAXN][MAXN], deg[MAXN];

typedef struct {
    int node;
    int color;
} StackNode;

typedef struct {
    StackNode *data;
    int top;
} Stack;

void initStack(Stack *s) {
    s->data = (StackNode *)malloc(MAXN * sizeof(StackNode));
    s->top = -1;
}

void push(Stack *s, StackNode node) {
    s->data[++(s->top)] = node;
}

StackNode pop(Stack *s) {
    return s->data[(s->top)--];
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool dfs(int x) {
    Stack stk;
    initStack(&stk);
    push(&stk, (StackNode){x, 1});
    bool flag = true;

    while (!isEmpty(&stk)) {
        StackNode current = pop(&stk);
        int u = current.node;
        int col = current.color;

        if (vis[u]) {
            flag &= (vis[u] == col);
            continue;
        }
        vis[u] = col;

        for (int i = 0; i < deg[u]; i++) {
            push(&stk, (StackNode){g[u][i], 3 - col});
        }
    }

    free(stk.data);
    return flag;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i <= n; i++) {
        deg[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][deg[u]++] = v;
        g[v][deg[v]++] = u;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (deg[i] == 0) {
                ci++;
            } else {
                if (dfs(i)) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }

    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);
    return 0;
}

// <END-OF-CODE>
