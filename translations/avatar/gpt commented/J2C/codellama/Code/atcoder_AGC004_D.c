#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int n;
    int k;
    int answer;
    bool isCalculate;
    int **lists;
} Calculator;

Calculator *calculator_new(int n, int k, int *as) {
    Calculator *calculator = malloc(sizeof(Calculator));
    calculator->n = n;
    calculator->k = k;
    calculator->answer = 0;
    calculator->isCalculate = false;
    calculator->lists = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        calculator->lists[i] = malloc(sizeof(int) * n);
        memset(calculator->lists[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        int j = as[i];
        if (i > 0) {
            calculator->lists[j][i] = 1;
        } else if (j > 0) {
            calculator->answer++;
        }
    }
    return calculator;
}

void calculator_free(Calculator *calculator) {
    for (int i = 0; i < calculator->n; i++) {
        free(calculator->lists[i]);
    }
    free(calculator->lists);
    free(calculator);
}

int calculator_calculate(Calculator *calculator) {
    if (!calculator->isCalculate) {
        calculator->dfs(calculator, 0, 0);
        calculator->isCalculate = true;
    }
    return calculator->answer;
}

void calculator_dfs(Calculator *calculator, int a, int pre) {
    int h = 0;
    for (int i = 0; i < calculator->n; i++) {
        if (calculator->lists[a][i] == 1) {
            h = max(h, calculator->dfs(calculator, i, a));
        }
    }
    if (pre > 0 && h == calculator->k - 1) {
        h = 0;
        calculator->answer++;
    } else {
        h++;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *as = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }
    Calculator *calculator = calculator_new(n, k, as);
    printf("%d\n", calculator_calculate(calculator));
    calculator_free(calculator);
    free(as);
    return 0;
}

