#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *children;
    int child_count;
} Node;

typedef struct Calculator {
    int k;
    int answer;
    int isCalculate;
    Node *lists;
} Calculator;

void dfs(Calculator *calc, int a, int pre, int *h) {
    int max_h = 0;
    for (int i = 0; i < calc->lists[a].child_count; i++) {
        int child = calc->lists[a].children[i];
        dfs(calc, child, a, &max_h);
    }
    if (pre > 0 && max_h == calc->k - 1) {
        max_h = 0;
        calc->answer++;
    } else {
        max_h++;
    }
    *h = max_h;
}

void calculate(Calculator *calc) {
    if (!calc->isCalculate) {
        int h = 0;
        dfs(calc, 0, -1, &h);
        calc->isCalculate = 1;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    Calculator calc;
    calc.k = k;
    calc.answer = 0;
    calc.isCalculate = 0;
    calc.lists = (Node *)malloc(n * sizeof(Node));

    for (int i = 0; i < n; i++) {
        calc.lists[i].children = (int *)malloc(n * sizeof(int));
        calc.lists[i].child_count = 0;
    }

    for (int i = 0; i < n; i++) {
        int j;
        scanf("%d", &j);
        j--; // Adjusting for 0-based index
        if (i > 0) {
            calc.lists[j].children[calc.lists[j].child_count++] = i;
        } else if (j > 0) {
            calc.answer++;
        }
    }

    calculate(&calc);
    printf("%d\n", calc.answer);

    for (int i = 0; i < n; i++) {
        free(calc.lists[i].children);
    }
    free(calc.lists);

    return 0;
}

// <END-OF-CODE>
