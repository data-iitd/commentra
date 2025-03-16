#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 100000

// Function to read a line of input and strip whitespace
char* input() {
    char *line = (char*)malloc(1000 * sizeof(char));
    fgets(line, 1000, stdin);
    line[strcspn(line, "\n")] = 0;
    return line;
}

// Function to read an integer from input
int INT() {
    char *line = input();
    return atoi(line);
}

// Function to read a map of integers from input
void MAP(int *a, int *b) {
    char *line = input();
    sscanf(line, "%d %d", a, b);
}

// Function to read a list of integers from input
int* LIST() {
    char *line = input();
    int *arr = (int*)malloc(100 * sizeof(int));
    int i = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read multiple lists of integers and zip them together
void ZIP(int n, int **arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = LIST();
    }
}

// Set the recursion limit to a high value
#undef _GLIBCXX_HAVE_THREADS
#define _GLIBCXX_HAVE_THREADS 0

// Define constants for infinity and modulo
#define INF 0x7FFFFFFF
#define MOD 1000000007

// Read the number of strings to process
int N;

// Read N strings from input
char** S;

// Define the target characters to count
char* march = "MARCH";

// Initialize a list to count occurrences of each target character
int march_lis[5] = {0};

int main() {
    N = INT();
    S = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        S[i] = input();
    }

    // Count the occurrences of each character in the input strings
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            if (strchr(S[i], march[j]) != NULL) {
                march_lis[j]++;
            }
        }
    }

    // Initialize the answer variable to store the result
    long long ans = 0;

    // Calculate the number of ways to choose 3 different characters from the counts
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += (long long)march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    // Print the final answer
    printf("%lld\n", ans);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(S[i]);
    }
    free(S);

    return 0;
}
