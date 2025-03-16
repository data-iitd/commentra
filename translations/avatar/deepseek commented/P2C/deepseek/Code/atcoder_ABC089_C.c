#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 100000

// Function to read a single line of input
char* input() {
    char* line = (char*)malloc(1000 * sizeof(char));
    if (fgets(line, 1000, stdin) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        return line;
    }
    return NULL;
}

// Function to convert input to an integer
int INT() {
    char* line = input();
    return atoi(line);
}

// Function to read a map of integers
void MAP(int* a, int* b) {
    char* line = input();
    sscanf(line, "%d %d", a, b);
}

// Function to convert input to a list of integers
int* LIST() {
    char* line = input();
    int* arr = (int*)malloc(100 * sizeof(int));
    int i = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to create combinations from a list of tuples
void ZIP(int n, int** result) {
    for (int i = 0; i < n; i++) {
        result[i] = LIST();
    }
}

// Set recursion limit to prevent recursion errors
#define _CRT_SECURE_NO_WARNINGS

// Define constants
#define INF 0x7FFFFFFF
#define MOD 1000000007

// Import numpy for numerical operations
#include <math.h>

// Read the number of strings
int N;

// Read the list of strings
char** S;

// List of characters that can be selected
char march[5] = {'M', 'A', 'R', 'C', 'H'};

// Initialize a list to count occurrences of each character in 'march'
int march_lis[5] = {0};

// Calculate the number of combinations of three elements from march_lis
int main() {
    N = INT();
    S = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        S[i] = input();
        for (int j = 0; j < 5; j++) {
            if (S[i][0] == march[j] || S[i][0] == tolower(march[j])) {
                march_lis[j]++;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(S[i]);
    }
    free(S);

    return 0;
}
