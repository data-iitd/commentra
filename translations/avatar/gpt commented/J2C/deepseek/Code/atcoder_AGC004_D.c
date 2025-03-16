#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int k;
    int answer;
    int isCalculate;
    int **lists;
} Calculator;

void dfs(int a, int pre, int *h, Calculator *calc);

int main() {
    int n, k;
    int *as;
    int i;
    Calculator calc;

    scanf("%d %d", &n, &k);
    as = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        as[i]--;
    }

    calc.k = k;
    calc.answer = 0;
    calc.isCalculate = 0;
    calc.lists = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        calc.lists[i] = (int *)malloc(0);
    }

    for (i = 0; i < n; i++) {
        int j = as[i];
        if (i > 0) {
            calc.lists[j] = (int *)realloc(calc.lists[j], (calc.lists[j][0] + 1) * sizeof(int));
            calc.lists[j][calc.lists[j][0] + 1] = i;
        } else if (j > 0) {
            calc.answer++;
        }
    }

    free(as);

    dfs(0, 0, &calc.answer, &calc);
    printf("%d\n", calc.answer);

    for (i = 0; i < n; i++) {
        free(calc.lists[i]);
    }
    free(calc.lists);

    return 0;
}

void dfs(int a, int pre, int *h, Calculator *calc) {
    int i;
    int *h_array = (int *)malloc(calc->lists[a][0] * sizeof(int));
    *h = 0;

    for (i = 1; i <= calc->lists[a][0]; i++) {
        dfs(calc->lists[a][i], a, &h_array[i - 1], calc);
        *h = (*h > h_array[i - 1]) ? *h : h_array[i - 1];
    }

    if (pre > 0 && *h == calc->k - 1) {
        *h = 0;
        calc->answer++;
    } else {
        (*h)++;
    }

    free(h_array);
}
