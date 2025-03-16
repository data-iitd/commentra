#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int readInt() {
    int result;
    scanf("%d", &result);
    return result;
}

void genid(int a, int b, int *id) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    *id = a * 100000 + b;
}

int main() {
    int N = readInt();

    int ab[MAX_N][2];
    int edges[MAX_N][MAX_N] = {0};
    for (int i = 0; i < N - 1; i++) {
        int a = readInt() - 1;
        int b = readInt() - 1;
        ab[i][0] = a;
        ab[i][1] = b;
        edges[a][edges[a][0]++] = b;
        edges[b][edges[b][0]++] = a;
    }

    int colors[MAX_N * 100000] = {0};
    int queue[MAX_N * 3];
    int front = 0, rear = 0;
    queue[rear++] = 0;
    queue[rear++] = -1;
    queue[rear++] = -1;

    while (front < rear) {
        int currentNode = queue[front++];
        int usedColor = queue[front++];
        int parentNode = queue[front++];
        int color = 1;
        for (int i = 0; i < edges[currentNode][0]; i++) {
            int childNode = edges[currentNode][i + 1];
            if (childNode == parentNode) {
                continue;
            }
            if (color == usedColor) {
                color++;
            }
            int id;
            genid(currentNode, childNode, &id);
            colors[id] = color;
            queue[rear++] = childNode;
            queue[rear++] = color;
            queue[rear++] = currentNode;
            color++;
        }
    }

    int K = 0;
    for (int i = 0; i < N; i++) {
        if (edges[i][0] > K) {
            K = edges[i][0];
        }
    }
    printf("%d\n", K);

    for (int i = 0; i < N - 1; i++) {
        int a = ab[i][0];
        int b = ab[i][1];
        int id;
        genid(a, b, &id);
        printf("%d\n", colors[id]);
    }

    return 0;
}
