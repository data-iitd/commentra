#include <stdio.h>

#define MAX_QUERIES 1000

typedef struct {
    int t; // Number of queries
    int queries[MAX_QUERIES][3]; // Array to hold the queries
} CodeforcesTask397BSolution;

void read_input(CodeforcesTask397BSolution *solution) {
    // Read the number of queries from input
    scanf("%d", &solution->t);
    // Read each query and store it in the queries array
    for (int i = 0; i < solution->t; i++) {
        scanf("%d %d %d", &solution->queries[i][0], &solution->queries[i][1], &solution->queries[i][2]);
    }
}

void process_task(CodeforcesTask397BSolution *solution, char result[][4]) {
    // Process each query to determine if the condition is met
    for (int i = 0; i < solution->t; i++) {
        int k = solution->queries[i][0] / solution->queries[i][1];
        // Check if k multiplied by query[2] is at least query[0]
        if (k * solution->queries[i][2] >= solution->queries[i][0]) {
            sprintf(result[i], "Yes");
        } else {
            sprintf(result[i], "No");
        }
    }
}

int main() {
    CodeforcesTask397BSolution solution;
    char result[MAX_QUERIES][4]; // Array to hold results for each query

    // Read input data
    read_input(&solution);
    // Process the task based on the input data
    process_task(&solution, result);
    
    // Print the final results
    for (int i = 0; i < solution.t; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}

// <END-OF-CODE>
