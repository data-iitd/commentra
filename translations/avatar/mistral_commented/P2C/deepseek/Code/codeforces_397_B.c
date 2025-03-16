#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char result[4]; // "Yes" or "No", 4 characters including null terminator
    int t; // Number of queries
    int** queries; // Array of queries
} CodeforcesTask397BSolution;

void read_input(CodeforcesTask397BSolution* solution) {
    scanf("%d", &solution->t);
    solution->queries = (int**)malloc(solution->t * sizeof(int*));
    for (int i = 0; i < solution->t; i++) {
        solution->queries[i] = (int*)malloc(3 * sizeof(int));
        scanf("%d %d %d", &solution->queries[i][0], &solution->queries[i][1], &solution->queries[i][2]);
    }
}

void process_task(CodeforcesTask397BSolution* solution) {
    char* res = (char*)malloc(solution->t * 3 * sizeof(char)); // Allocate memory for results
    int index = 0;
    for (int i = 0; i < solution->t; i++) {
        int k = solution->queries[i][0] / solution->queries[i][1];
        if (k * solution->queries[i][2] >= solution->queries[i][0]) {
            strcpy(res + index, "Yes");
        } else {
            strcpy(res + index, "No");
        }
        index += 3; // Move to the next position in the result array
    }
    strcpy(solution->result, res);
    free(res); // Free the allocated memory for results
}

char* get_result(CodeforcesTask397BSolution* solution) {
    return solution->result;
}

int main() {
    CodeforcesTask397BSolution solution;
    read_input(&solution);
    process_task(&solution);
    printf("%s\n", get_result(&solution));

    // Free allocated memory for queries
    for (int i = 0; i < solution.t; i++) {
        free(solution.queries[i]);
    }
    free(solution.queries);

    return 0;
}
