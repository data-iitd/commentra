
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *array[100000];
    int size;
} Graph;

void initGraph(Graph *g){
    g->size = 100000;
    for(int i = 0; i < g->size; i++){
        g->array[i] = NULL;
    }
}

void addEdge(Graph *g, int from, int to){
    Node *n = (Node *)malloc(sizeof(Node));
    n->value = to;
    n->next = g->array[from];
    g->array[from] = n;
}

int dfs(Graph *g, int v, int *used, int *grundy){
    used[v] = 1;
    grundy[v] = 0;
    Node *n = g->array[v];
    while(n!= NULL){
        if(used[n->value] == 0){
            grundy[v] ^= (dfs(g, n->value, used, grundy)+1);
        }
        n = n->next;
    }
    return grundy[v];
}

int main(){
    Graph g;
    initGraph(&g);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(&g, x-1, y-1);
        addEdge(&g, y-1, x-1);
    }
    int used[100000];
    int grundy[100000];
    for(int i = 0; i < 100000; i++){
        used[i] = 0;
    }
    dfs(&g, 0, used, grundy);
    if(grundy[0]!= 0){
        printf("Alice\n");
    }else{
        printf("Bob\n");
    }
    return 0;
}

