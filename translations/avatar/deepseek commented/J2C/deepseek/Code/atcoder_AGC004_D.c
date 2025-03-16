#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

typedef struct {
    int k;
    int answer;
    int isCalculate;
    int lists[MAX_N][MAX_N];
    int listSize[MAX_N];
} Calculator;

void initializeCalculator(Calculator *calc, int n, int k) {
    calc->k = k;
    calc->answer = 0;
    calc->isCalculate = 0;
    for (int i = 0; i < n; i++) {
        calc->listSize[i] = 0;
    }
}

void addRelationship(Calculator *calc, int parent, int child) {
    calc->lists[parent][calc->listSize[parent]++] = child;
}

void dfs(Calculator *calc, int a, int pre) {
    int h = 0;
    for (int i = 0; i < calc->listSize[a]; i++) {
        dfs(calc, calc->lists[a][i], a);
        h = (h > calc->listSize[a][i]) ? h : calc->listSize[a][i];
    }
    if (pre != 0 && h == calc->k - 1) {
        h = 0;
        calc->answer++;
    } else {
        h++;
    }
}

int calculate(Calculator *calc) {
    if (!calc->isCalculate) {
        dfs(calc, 0, 0);
        calc->isCalculate = 1;
    }
    return calc->answer;
}

int main() {
    int n, k;
    int as[MAX_N];
    Calculator calc;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        as[i]--;
    }

    initializeCalculator(&calc, n, k);
    for (int i = 0; i < n; i++) {
        int j = as[i];
        if (i != 0) {
            addRelationship(&calc, j, i);
        } else if (j != 0) {
            calc.answer++;
        }
    }

    printf("%d\n", calculate(&calc));
    return 0;
}

