

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    long pattern;
    int index;
    struct Node **children;
    int numChildren;
    int parent;
} Node;

void setParent(Node *node, int K, int parent, int use, Node *nodes[], int N) {
    node->pattern = K - use;
    node->parent = parent;
    int count = 1;
    if (parent!= -1) {
        count++;
    }
    for (int i = 0; i < node->numChildren; i++) {
        int childIndex = node->children[i];
        if (childIndex == node->parent) {
            continue;
        }
        setParent(nodes[childIndex], K, node->index, count, nodes, N);
        count++;
    }
}

void solve(int N, int K, Node *nodes[]) {
    for (int i = 0; i < N; i++) {
        nodes[i]->children = (Node **)malloc(sizeof(Node *) * N);
        nodes[i]->numChildren = 0;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        nodes[a]->children[nodes[a]->numChildren] = b;
        nodes[a]->numChildren++;
        nodes[b]->children[nodes[b]->numChildren] = a;
        nodes[b]->numChildren++;
    }

    setParent(nodes[0], K, -1, 0, nodes, N);

    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i]->pattern) % 1000000007;
    }

    printf("%ld\n", patterns);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    Node *nodes[N];
    for (int i = 0; i < N; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->index = i;
    }

    solve(N, K, nodes);

    for (int i = 0; i < N; i++) {
        free(nodes[i]->children);
        free(nodes[i]);
    }

    return 0;
}

