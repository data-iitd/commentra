

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    int size;
    int capacity;
    Node **array;
} List;

typedef struct {
    int n;
    int k;
    List *lists;
    int answer;
    bool isCalculate;
} Calculator;

Calculator *newCalculator(int n, int k) {
    Calculator *calc = (Calculator *)malloc(sizeof(Calculator));
    calc->n = n;
    calc->k = k;
    calc->lists = (List *)malloc(sizeof(List) * n);
    for (int i = 0; i < n; i++) {
        calc->lists[i].size = 0;
        calc->lists[i].capacity = 10;
        calc->lists[i].array = (Node **)malloc(sizeof(Node *) * calc->lists[i].capacity);
    }
    calc->answer = 0;
    calc->isCalculate = false;
    return calc;
}

void addEdge(Calculator *calc, int from, int to) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = to;
    node->next = NULL;
    if (calc->lists[from].size == calc->lists[from].capacity) {
        calc->lists[from].capacity *= 2;
        calc->lists[from].array = (Node **)realloc(calc->lists[from].array, sizeof(Node *) * calc->lists[from].capacity);
    }
    calc->lists[from].array[calc->lists[from].size++] = node;
}

int calculate(Calculator *calc) {
    if (!calc->isCalculate) {
        dfs(calc, 0, 0);
        calc->isCalculate = true;
    }
    return calc->answer;
}

int dfs(Calculator *calc, int a, int pre) {
    int h = 0;
    for (int i = 0; i < calc->lists[a].size; i++) {
        h = fmax(h, dfs(calc, calc->lists[a].array[i]->value, a));
    }
    if (pre!= 0 && h == calc->k - 1) {
        h = 0;
        calc->answer++;
    } else {
        h++;
    }
    return h;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Calculator *calc = newCalculator(n, k);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        addEdge(calc, a - 1, i);
    }
    printf("%d\n", calculate(calc));
    return 0;
}

