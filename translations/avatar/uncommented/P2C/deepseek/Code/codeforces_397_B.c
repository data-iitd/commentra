#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char result[10];
    int t;
    int** queries;
} CodeforcesTask397BSolution;

void read_input(CodeforcesTask397BSolution* solution) {
    scanf("%d", &solution->t);
    solution->queries = (int**)malloc(solution->t * sizeof(int*));
    for (int i = 0; i < solution->t; i++) {
        solution->queries[i] = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            scanf("%d", &solution->queries[i][j]);
        }
    }
}

void process_task(CodeforcesTask397BSolution* solution) {
    for (int i = 0; i < solution->t; i++) {
        int k = solution->queries[i][0] / solution->queries[i][1];
        if (k * solution->queries[i][2] >= solution->queries[i][0]) {
            strcpy(solution->result, "Yes");
        } else {
            strcpy(solution->result, "No");
        }
    }
}

void get_result(CodeforcesTask397BSolution* solution) {
    for (int i = 0; i < solution->t; i++) {
        printf("%s\n", solution->result);
    }
}

int main() {
    CodeforcesTask397BSolution solution;
    read_input(&solution);
    process_task(&solution);
    get_result(&solution);
    return 0;
}
