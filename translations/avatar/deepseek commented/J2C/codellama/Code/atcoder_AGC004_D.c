
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int n;
    int k;
    int *as;
} Input;

typedef struct {
    int answer;
    int *lists;
} Calculator;

void read_input(Input *input) {
    scanf("%d %d", &input->n, &input->k);
    input->as = (int *)malloc(input->n * sizeof(int));
    for (int i = 0; i < input->n; i++) {
        scanf("%d", &input->as[i]);
    }
}

void init_calculator(Calculator *calculator, Input *input) {
    calculator->answer = 0;
    calculator->lists = (int *)malloc(input->n * sizeof(int));
    for (int i = 0; i < input->n; i++) {
        calculator->lists[i] = 0;
    }
    for (int i = 0; i < input->n; i++) {
        int j = input->as[i];
        if (i > 0) {
            calculator->lists[j]++;
        } else if (j > 0) {
            calculator->answer++;
        }
    }
}

int dfs(Calculator *calculator, int a, int pre) {
    int h = 0;
    for (int i = 0; i < calculator->lists[a]; i++) {
        int j = a + i + 1;
        h = max(h, dfs(calculator, j, a));
    }
    if (pre > 0 && h == calculator->k - 1) {
        h = 0;
        calculator->answer++;
    } else {
        h++;
    }
    return h;
}

int calculate(Calculator *calculator) {
    if (calculator->answer == 0) {
        dfs(calculator, 0, 0);
    }
    return calculator->answer;
}

int main() {
    Input input;
    read_input(&input);
    Calculator calculator;
    init_calculator(&calculator, &input);
    printf("%d\n", calculate(&calculator));
    return 0;
}

