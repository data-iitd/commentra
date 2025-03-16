#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct Node {
    long pattern;
    int index;
    int parent;
    int *children;
    int children_count;
} Node;

void setParent(Node *nodes, int K, int index, int parent, int use, int count) {
    nodes[index].pattern = K - use;
    nodes[index].parent = parent;
    count++;
    
    for (int i = 0; i < nodes[index].children_count; i++) {
        int child_index = nodes[index].children[i];
        if (child_index == parent) {
            continue;
        }
        setParent(nodes, K, child_index, index, count, count);
    }
}

void solve() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    Node *nodes = (Node *)malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++) {
        nodes[i].index = i;
        nodes[i].pattern = 0;
        nodes[i].parent = -1;
        nodes[i].children_count = 0;
        nodes[i].children = (int *)malloc((N - 1) * sizeof(int)); // Max children can be N-1
    }
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; // Convert to 0-based index
        b--; // Convert to 0-based index
        
        nodes[a].children[nodes[a].children_count++] = b;
        nodes[b].children[nodes[b].children_count++] = a;
    }
    
    setParent(nodes, K, 0, -1, 0, 0);
    
    long patterns = 1;
    for (int i = 0; i < N; i++) {
        patterns = (patterns * nodes[i].pattern) % MOD;
    }
    
    printf("%ld\n", patterns);
    
    for (int i = 0; i < N; i++) {
        free(nodes[i].children);
    }
    free(nodes);
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
