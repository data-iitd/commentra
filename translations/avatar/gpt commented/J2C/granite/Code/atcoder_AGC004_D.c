
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    int size;
    int capacity;
    Node **array;
} Graph;

Graph *createGraph(int capacity) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size = 0;
    graph->capacity = capacity;
    graph->array = (Node **)malloc(sizeof(Node *) * capacity);
    for (int i = 0; i < capacity; i++) {
        graph->array[i] = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, int from, int to) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = to;
    node->next = graph->array[from];
    graph->array[from] = node;
    graph->size++;
}

void dfs(Graph *graph, int *answer, int *height, int current, int parent) {
    int h = 0;
    Node *node = graph->array[current];
    while (node!= NULL) {
        dfs(graph, answer, height, node->value, current);
        h = fmax(*height, h);
        node = node->next;
    }
    if (parent!= -1 && h == *answer) {
        h = 0;
        (*answer)++;
    } else {
        h++;
    }
    *height = h;
}

int calculate(Graph *graph, int k) {
    int answer = 0;
    int height = 0;
    dfs(graph, &answer, &height, 0, -1);
    return answer;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Graph *graph = createGraph(n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (i > 0) {
            addEdge(graph, a - 1, i);
        } else if (a > 0) {
            answer++;
        }
    }
    printf("%d\n", calculate(graph, k));
    return 0;
}
