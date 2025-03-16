
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int n;
    int k;
    int *as;
} Input;

typedef struct {
    int answer;
    int isCalculate;
    int **lists;
} Calculator;

void readInput(Input *input) {
    scanf("%d %d", &input->n, &input->k);
    input->as = (int *)malloc(input->n * sizeof(int));
    for (int i = 0; i < input->n; i++) {
        scanf("%d", &input->as[i]);
    }
}

void buildGraph(Input *input, Calculator *calculator) {
    calculator->lists = (int **)malloc(input->n * sizeof(int *));
    for (int i = 0; i < input->n; i++) {
        calculator->lists[i] = (int *)malloc(input->n * sizeof(int));
        memset(calculator->lists[i], 0, input->n * sizeof(int));
    }

    for (int i = 0; i < input->n; i++) {
        int j = input->as[i];
        if (0 < i) {
            calculator->lists[j][i] = 1;
        } else if (0 < j) {
            calculator->answer++;
        }
    }
}

int dfs(int a, int pre, Calculator *calculator) {
    int h = 0;

    for (int i = 0; i < calculator->n; i++) {
        if (calculator->lists[a][i] == 1) {
            h = max(h, dfs(i, a, calculator));
        }
    }

    if (0 < pre && h == calculator->k - 1) {
        h = 0;
        calculator->answer++;
    } else {
        h++;
    }

    return h;
}

int calculate(Calculator *calculator) {
    if (!calculator->isCalculate) {
        dfs(0, -1, calculator);
        calculator->isCalculate = 1;
    }
    return calculator->answer;
}

int main() {
    Input input;
    readInput(&input);

    Calculator calculator;
    buildGraph(&input, &calculator);

    printf("%d\n", calculate(&calculator));

    return 0;
}

