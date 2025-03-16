#include <stdio.h>

typedef struct {
    int t;
    int queries[100][3]; // Assuming a maximum of 100 queries
    char result[100][4]; // To store "Yes" or "No" for each query
} CodeforcesTask397BSolution;

void read_input(CodeforcesTask397BSolution *solution) {
    scanf("%d", &solution->t);
    for (int i = 0; i < solution->t; i++) {
        scanf("%d %d %d", &solution->queries[i][0], &solution->queries[i][1], &solution->queries[i][2]);
    }
}

void process_task(CodeforcesTask397BSolution *solution) {
    for (int i = 0; i < solution->t; i++) {
        int k = solution->queries[i][0] / solution->queries[i][1];
        if (k * solution->queries[i][2] >= solution->queries[i][0]) {
            sprintf(solution->result[i], "Yes");
        } else {
            sprintf(solution->result[i], "No");
        }
    }
}

void print_result(CodeforcesTask397BSolution *solution) {
    for (int i = 0; i < solution->t; i++) {
        printf("%s\n", solution->result[i]);
    }
}

int main() {
    CodeforcesTask397BSolution solution;
    read_input(&solution);
    process_task(&solution);
    print_result(&solution);
    return 0;
}

// <END-OF-CODE>
