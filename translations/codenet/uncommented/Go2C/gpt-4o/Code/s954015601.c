#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_COLOR 100000

int edges[MAX_N][MAX_N];
int edge_count[MAX_N];
int colors[MAX_N * 2]; // To store colors for edges
int ab[MAX_N][2]; // To store the edges
int N;

int genid(int a, int b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    return a * 100000 + b;
}

void dfs(int currentNode, int usedColor, int parentNode) {
    int color = 1;
    for (int i = 0; i < edge_count[currentNode]; i++) {
        int childNode = edges[currentNode][i];
        if (childNode == parentNode) {
            continue;
        }
        if (color == usedColor) {
            color++;
        }
        colors[genid(currentNode, childNode)] = color;
        dfs(childNode, color, currentNode);
        color++;
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        ab[i][0] = a;
        ab[i][1] = b;
        edges[a][edge_count[a]++] = b;
        edges[b][edge_count[b]++] = a;
    }

    dfs(0, -1, -1);

    int K = -1;
    for (int i = 0; i < N; i++) {
        if (edge_count[i] > K) {
            K = edge_count[i];
        }
    }
    printf("%d\n", K);

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i][0], ab[i][1])]);
    }

    return 0;
}

// <END-OF-CODE>
