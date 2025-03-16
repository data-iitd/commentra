#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 100000

int numNode, numEdge;
int visited[MAX_NODE];
int connect[MAX_NODE][MAX_NODE];
int odd[MAX_NODE];
char print[MAX_NODE][MAX_NODE];

void dfs(int crt, int parent);

int main() {
    scanf("%d %d", &numNode, &numEdge);
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        connect[a - 1][b - 1] = 1;
        connect[b - 1][a - 1] = 1;
    }
    if (numEdge % 2!= 0) {
        printf("-1\n");
        return 0;
    }
    memset(visited, 0, sizeof(visited));
    memset(odd, 0, sizeof(odd));
    memset(print, 0, sizeof(print));
    dfs(0, -1);
    printf("%s", print);
    return 0;
}

void dfs(int crt, int parent) {
    visited[crt] = 1;
    int *crtConnect = connect[crt];
    for (int i = 0; i < numNode; i++) {
        if (crtConnect[i] == 0) {
            continue;
        }
        if (i == parent || visited[i] == 1) {
            continue;
        } else if (visited[i] == 2) {
            if (odd[i]) {
                printf("%d %d\n", i + 1, crt + 1);
                odd[i] = 0;
            } else {
                printf("%d %d\n", crt + 1, i + 1);
                odd[crt] = 1;
            }
        } else {
            dfs(i, crt);
            if (odd[i]) {
                printf("%d %d\n", i + 1, crt + 1);
                odd[i] = 0;
            } else {
                printf("%d %d\n", crt + 1, i + 1);
                odd[crt] = 1;
            }
        }
    }
    visited[crt] = 2;
}

