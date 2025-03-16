// 深さ優先探索
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// genid generates a unique identifier for an edge between two nodes.
int genid(int a, int b) {
    if (b < a) {
        a = b;
        b = a;
    }
    return a * 100000 + b;
}

int main() {
    // Read the number of nodes from standard input.
    int N = 0;
    scanf("%d", &N);

    // Initialize a slice to store edges and an adjacency list for the graph.
    int ab[N - 1][2];
    int **edges = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(sizeof(int) * 100000);
    }
    for (int i = 0; i < N - 1; i++) {
        // Read edge information and populate the adjacency list.
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        ab[i][0] = a - 1;
        ab[i][1] = b - 1;
        edges[a - 1][b - 1] = 1;
        edges[b - 1][a - 1] = 1;
    }

    // Initialize a map to store the color of each edge and a queue for DFS traversal.
    int colors[100000];
    int q[N][3];
    q[0][0] = 0;
    q[0][1] = -1;
    q[0][2] = -1;
    for (int i = 0; i < N; i++) {
        colors[genid(q[i][0], q[i][1])] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        // Pop the last element from the queue for DFS traversal.
        int currentNode = q[i][0];
        int usedColor = q[i][1];
        int parentNode = q[i][2];
        int color = 1;
        for (int j = 0; j < N; j++) {
            if (edges[currentNode][j] == 1 && j != parentNode) {
                if (color == usedColor) {
                    color++;
                }
                colors[genid(currentNode, j)] = color;
                q[i + 1][0] = j;
                q[i + 1][1] = color;
                q[i + 1][2] = currentNode;
                color++;
            }
        }
    }

    // Determine the maximum degree of any node in the graph.
    int K = -1;
    for (int i = 0; i < N; i++) {
        int t = 0;
        for (int j = 0; j < N; j++) {
            if (edges[i][j] == 1) {
                t++;
            }
        }
        if (t > K) {
            K = t;
        }
    }
    printf("%d\n", K);

    // Output the colors of the edges.
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }
    return 0;
}

