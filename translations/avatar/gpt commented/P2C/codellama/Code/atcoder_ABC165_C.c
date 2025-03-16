#include <stdio.h>
#include <stdlib.h>

// Generator function to iterate through input tokens
void iterate_tokens(char *line, int *i, int *j) {
    while (line[*i] != '\0') {
        while (line[*i] == ' ') {
            (*i)++;
        }
        *j = *i;
        while (line[*i] != ' ' && line[*i] != '\0') {
            (*i)++;
        }
        printf("%.*s\n", *i - *j, line + *j);
    }
}

// Recursive function to explore combinations of numbers
void rec(int *A, int N, int M, int Q, int *a, int *b, int *c, int *d, int *res) {
    // Base case: if the length of A equals N, calculate the score
    if (N == 0) {
        int ans = 0;
        // Check each query to see if it contributes to the score
        for (int i = 0; i < Q; i++) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                ans += d[i];  // Add the score from the query if it matches
            }
        }
        // Update the maximum score found
        *res = *res > ans ? *res : ans;
        return;
    }
    
    // Determine the starting point for the next number to be added
    int last_max = 1;
    if (N > 0) {
        last_max = A[N - 1];
    }
    
    // Iterate through possible values to add to the combination
    for (int i = last_max; i <= M; i++) {
        A[N] = i;
        rec(A, N + 1, M, Q, a, b, c, d, res);
    }
}

// Entry point of the program
int main() {
    // Read the values of N, M, and Q from input
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    
    // Initialize arrays to hold the query parameters
    int a[Q], b[Q], c[Q], d[Q];
    
    // Read the query parameters from input
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    
    // Initialize the result variable to store the maximum score
    int res = 0;
    
    // Start the recursive exploration with an empty list
    int A[N];
    rec(A, 0, M, Q, a, b, c, d, &res);
    
    // Print the maximum score found
    printf("%d\n", res);
    return 0;
}

