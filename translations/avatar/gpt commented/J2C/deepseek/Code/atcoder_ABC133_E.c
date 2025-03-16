#include <stdio.h>
#include <stdlib.h>
#include <linkedlist.h>

#define MOD 1000000007

typedef struct Node {
    long pattern;
    int index;
    LinkedList children;
    int parent;
} Node;

typedef struct {
    Node* nodes;
} Main;

void setParent(int K, int parent, int use, Node* nodes, int N) {
    nodes[use].pattern = K - use;
    nodes[use].parent = parent;
    int count = 1;

    if (parent != -1) {
        count++;
    }

    for (int i = 0; i < nodes[use].children.size; i++) {
        int n = nodes[use].children.get(i);
        if (n == nodes[use].parent) {
            continue;
        }
        setParent(K, use, n, nodes, N);
        count++;
    }
}

void solve(Main* main) {
    int N, K;
    scanf("%d %d", &N, &K);
    Node* nodes = (Node*)malloc(N * sizeof(Node));

    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].children = createLinkedList();
        nodes[i].parent = -1;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        addNode(nodes[a].children, b);
        addNode(nodes[b].children, a);
    }

    setParent(K, -1, 0, nodes, N);

    long patterns = 1;

    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % MOD;
    }

    printf("%ld\n", patterns);
    free(nodes);
}

int main() {
    Main main;
    main.nodes = NULL;
    solve(&main);
    return 0;
}
