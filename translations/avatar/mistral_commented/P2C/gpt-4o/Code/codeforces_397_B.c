#include <stdio.h>
#include <stdlib.h>

#define MAX_QUERIES 1000

// Structure definition for CodeforcesTask397BSolution
typedef struct {
    int t;                  // Number of queries
    int queries[MAX_QUERIES][3]; // Array to store the queries
    char result[MAX_QUERIES * 4]; // Array to store the result strings
} CodeforcesTask397BSolution;

// Function to read input
void read_input(CodeforcesTask397BSolution *solution) {
    scanf("%d", &solution->t); // Read the number of queries
    for (int i = 0; i < solution->t; i++) {
        scanf("%d %d %d", &solution->queries[i][0], &solution->queries[i][1], &solution->queries[i][2]); // Read each query
    }
}

// Function to process the task
void process_task(CodeforcesTask397BSolution *solution) {
    char *result_ptr = solution->result; // Pointer to the result string
    for (int i = 0; i < solution->t; i++) {
        int k = solution->queries[i][0] / solution->queries[i][1]; // Calculate k
        if (k * solution->queries[i][2] >= solution->queries[i][0]) {
            result_ptr += sprintf(result_ptr, "Yes\n"); // Append "Yes" to result
        } else {
            result_ptr += sprintf(result_ptr, "No\n"); // Append "No" to result
        }
    }
}

// Function to get the result
void get_result(CodeforcesTask397BSolution *solution) {
    printf("%s", solution->result); // Print the result string
}

// Main function to run the code
int main() {
    CodeforcesTask397BSolution solution; // Create an instance of the structure
    read_input(&solution);                // Read the input
    process_task(&solution);              // Process the task
    get_result(&solution);                // Print the result
    return 0;
}

// <END-OF-CODE>
