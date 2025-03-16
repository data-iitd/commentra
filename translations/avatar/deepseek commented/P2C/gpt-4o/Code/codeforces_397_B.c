#include <stdio.h>

#define MAX_QUERIES 100

typedef struct {
    int t; // Number of test cases
    int queries[MAX_QUERIES][3]; // Store queries
    char result[MAX_QUERIES][4]; // Store results ("Yes" or "No")
} CodeforcesTask397BSolution;

// Function to read input
void read_input(CodeforcesTask397BSolution *solution) {
    scanf("%d", &solution->t); // Read the number of test cases
    for (int i = 0; i < solution->t; i++) {
        scanf("%d %d %d", &solution->queries[i][0], &solution->queries[i][1], &solution->queries[i][2]); // Read each query
    }
}

// Function to process each query
void process_task(CodeforcesTask397BSolution *solution) {
    for (int i = 0; i < solution->t; i++) {
        int k = solution->queries[i][0] / solution->queries[i][1]; // Calculate k
        if (k * solution->queries[i][2] >= solution->queries[i][0]) {
            snprintf(solution->result[i], sizeof(solution->result[i]), "Yes"); // Append "Yes"
        } else {
            snprintf(solution->result[i], sizeof(solution->result[i]), "No"); // Append "No"
        }
    }
}

// Function to print the final result
void get_result(CodeforcesTask397BSolution *solution) {
    for (int i = 0; i < solution->t; i++) {
        printf("%s\n", solution->result[i]); // Print each result
    }
}

int main() {
    CodeforcesTask397BSolution solution; // Create an instance of the solution
    read_input(&solution); // Read input
    process_task(&solution); // Process the task
    get_result(&solution); // Print the final result
    return 0;
}

// <END-OF-CODE>
