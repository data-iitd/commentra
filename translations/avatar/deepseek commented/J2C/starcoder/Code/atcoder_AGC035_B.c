#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numNode, numEdge;
    scanf("%d %d", &numNode, &numEdge);
    
    int connect[numNode][numNode];
    for (int i = 0; i < numNode; i++) {
        for (int j = 0; j < numNode; j++) {
            connect[i][j] = 0;
        }
    }
    
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
    
    int visited[numNode];
    int odd[numNode];
    for (int i = 0; i < numNode; i++) {
        visited[i] = 0;
        odd[i] = 0;
    }
    
    char print[numNode][numNode];
    for (int i = 0; i < numNode; i++) {
        for (int j = 0; j < numNode; j++) {
            print[i][j] = 0;
        }
    }
    
    dfs(0, -1, connect, visited, odd, print);
    
    printf("%s", print[0][numNode - 1]);
}

void dfs(int crt, int parent, int connect[][numNode], int visited[], int odd[], char print[][numNode]) {
    visited[crt] = 1;
    for (int child = 0; child < numNode; child++) {
        if (child == parent || visited[child] == 1) {
            continue;
        } else if (visited[child] == 2) {
            print[crt][child] = 1;
            odd[crt] =!odd[crt];
        } else {
            dfs(child, crt, connect, visited, odd, print);
            if (odd[child]) {
                print[child][crt] = 1;
                odd[child] =!odd[child];
            } else {
                print[crt][child] = 1;
                odd[crt] =!odd[crt];
            }
        }
    }
    visited[crt] = 2;
}

