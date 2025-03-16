

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node** lists;
    int n;
    int k;
    int answer;
    int isCalculate;
} Graph;

Graph* createGraph(int n, int k, int* as) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->lists = (Node**)malloc(sizeof(Node*) * n);
    for (int i = 0; i < n; i++) {
        graph->lists[i] = NULL;
    }
    graph->n = n;
    graph->k = k;
    graph->answer = 0;
    graph->isCalculate = 0;

    for (int i = 0; i < n; i++) {
        int j = as[i];
        if (i > 0) {
            Node* node = (Node*)malloc(sizeof(Node));
            node->data = j;
            node->next = graph->lists[j];
            graph->lists[j] = node;
        } else if (j > 0) {
            graph->answer++;
        }
    }

    return graph;
}

void dfs(Graph* graph, int a, int pre) {
    int h = 0;

    Node* node = graph->lists[a];
    while (node!= NULL) {
        dfs(graph, node->data, a);
        h = fmax(h, dfs(graph, node->data, a));
        node = node->next;
    }

    if (pre > 0 && h == graph->k - 1) {
        h = 0;
        graph->answer++;
    } else {
        h++;
    }

    return h;
}

int calculate(Graph* graph) {
    if (!graph->isCalculate) {
        dfs(graph, 0, -1);
        graph->isCalculate = 1;
    }
    return graph->answer;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* as = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    Graph* graph = createGraph(n, k, as);
    int result = calculate(graph);
    printf("%d\n", result);

    return 0;
}

