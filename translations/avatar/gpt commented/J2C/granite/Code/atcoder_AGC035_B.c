
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numNode, numEdge;
int *visited, *odd;
int **connect;

void dfs(int crt, int parent) {
    visited[crt] = 1;
    for (int i = 0; i < numNode; i++) {
        if (connect[crt][i] && i!= parent && visited[i] == 1) {
            dfs(i, crt);
            if (odd[i]) {
                printf("%d %d\n", i + 1, crt + 1);
                odd[crt] =!odd[crt];
            } else {
                printf("%d %d\n", crt + 1, i + 1);
                odd[i] =!odd[i];
            }
        } else if (connect[crt][i] && i!= parent && visited[i] == 2) {
            printf("%d %d\n", crt + 1, i + 1);
            odd[crt] =!odd[crt];
        }
    }
    visited[crt] = 2;
}

int main() {
    scanf("%d %d", &numNode, &numEdge);
    connect = (int **)malloc(numNode * sizeof(int *));
    for (int i = 0; i < numNode; i++) {
        connect[i] = (int *)malloc(numNode * sizeof(int));
    }
    for (int i = 0; i < numEdge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        connect[a - 1][b - 1] = connect[b - 1][a - 1] = 1;
    }
    if (numEdge % 2!= 0) {
        printf("-1\n");
        return 0;
    }
    visited = (int *)malloc(numNode * sizeof(int));
    odd = (int *)malloc(numNode * sizeof(int));
    dfs(0, -1);
    return 0;
}
