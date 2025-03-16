#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

// Structure for the stack
typedef struct {
    int vertex;
    int color;
} StackNode;

typedef struct {
    StackNode *data;
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->data = (StackNode *)malloc(MAXN * sizeof(StackNode));
    s->top = -1;
}

// Function to push an element onto the stack
void push(Stack *s, int vertex, int color) {
    s->data[++(s->top)] = (StackNode){vertex, color};
}

// Function to pop an element from the stack
StackNode pop(Stack *s) {
    return s->data[(s->top)--];
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Adjacency list representation of the graph
int g[MAXN][MAXN];
int gSize[MAXN];
int vis[MAXN];

int dfs(int x) {
    Stack stk;
    initStack(&stk);
    int flag = 1;

    push(&stk, x, 1);

    while (!isEmpty(&stk)) {
        StackNode node = pop(&stk);
        int u = node.vertex;
        int col = node.color;

        if (vis[u]) {
            flag &= (vis[u] == col);
            continue;
        }

        vis[u] = col;

        for (int i = 0; i < gSize[u]; i++) {
            int v = g[u][i];
            push(&stk, v, 3 - col);
        }
    }

    free(stk.data);
    return flag;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize the graph
    for (int i = 0; i <= n; i++) {
        gSize[i] = 0;
        vis[i] = 0;
    }

    int ci = 0, cb = 0, cc = 0;

    // Adding edges to the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][gSize[u]++] = v;
        g[v][gSize[v]++] = u;
    }

    // Finding the number of isolated vertices and connected components
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (gSize[i] == 0) {
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

    // Calculating and printing the final answer
    printf("%d\n", ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb);

    return 0;
}

// <END-OF-CODE>
