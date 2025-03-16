
#include <stdio.h>
#include <stdlib.h>

// Function to generate unique id based on two integers
int genid(int a, int b) {
    if (b < a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    // Multiply the larger number by 100000 and add the smaller number
    return a*100000 + b;
}

int main() {
    // Read the number of edges in the graph
    int N = 0;
    scanf("%d", &N);

    // Initialize an adjacency list and a 2D array to store the edges between nodes
    int **edges = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        edges[i] = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            edges[i][j] = 0;
        }
    }
    int **ab = (int **)malloc(sizeof(int *) * (N - 1));
    for (int i = 0; i < N - 1; i++) {
        ab[i] = (int *)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edges[a][b] = 1;
        edges[b][a] = 1;
        ab[i][0] = a;
        ab[i][1] = b;
    }

    // Initialize a map to store the colors of each connected component
    int *colors = (int *)malloc(sizeof(int) * (N * (N - 1) / 2));
    for (int i = 0; i < N * (N - 1) / 2; i++) {
        colors[i] = 0;
    }

    // Initialize a queue to perform DFS
    int **q = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
        q[i] = (int *)malloc(sizeof(int) * 3);
    }
    int head = 0, tail = 0;
    q[tail][0] = 0;
    q[tail][1] = -1;
    q[tail][2] = -1;
    tail++;

    while (head < tail) {
        // Dequeue the current node, its color, and its parent node
        int currentNode = q[head][0];
        int usedColor = q[head][1];
        int parentNode = q[head][2];
        head++;

        // Set the color of the current node to the next available color
        int color = 1;
        for (int i = 0; i < N; i++) {
            if (edges[currentNode][i] == 1 && i!= parentNode) {
                if (color == usedColor) {
                    color++;
                }
                // Assign the color to the child node and add it to the queue with the current node as its parent node
                colors[genid(currentNode, i)] = color;
                q[tail][0] = i;
                q[tail][1] = color;
                q[tail][2] = currentNode;
                tail++;
                // Increment the color for the next iteration
                color++;
            }
        }
    }

    // Initialize a variable to store the maximum number of edges in a connected component
    int K = 0;
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
    // Print the maximum number of edges in a connected component
    printf("%d\n", K);

    // Iterate through all edges in the graph and print their colors
    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }

    // Free memory
    for (int i = 0; i < N; i++) {
        free(edges[i]);
        free(q[i]);
    }
    free(edges);
    free(q);
    for (int i = 0; i < N - 1; i++) {
        free(ab[i]);
    }
    free(ab);
    free(colors);

    return 0;
}
