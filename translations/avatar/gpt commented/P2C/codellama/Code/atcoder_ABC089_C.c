
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a line of input and strip whitespace
char* input() {
    char* str = malloc(1000000 * sizeof(char));
    fgets(str, 1000000, stdin);
    str[strcspn(str, "\n")] = 0;
    return str;
}

// Function to read an integer from input
int INT() {
    char* str = input();
    return atoi(str);
}

// Function to read a map of integers from input
int* MAP() {
    char* str = input();
    int* arr = malloc(1000000 * sizeof(int));
    int i = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read a list of integers from input
int* LIST() {
    char* str = input();
    int* arr = malloc(1000000 * sizeof(int));
    int i = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to read multiple lists of integers and zip them together
int** ZIP(int n) {
    int** arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = LIST();
    }
    return arr;
}

// Set the recursion limit to a high value
#define RECURSION_LIMIT 1000000000

// Define constants for infinity and modulo
#define INF 1000000000
#define mod 1000000007

// Import numpy for numerical operations (though not used in the code)
#include <numpy/arrayobject.h>

// Read the number of strings to process
int N = INT();

// Read N strings from input
char** S = malloc(N * sizeof(char*));
for (int i = 0; i < N; i++) {
    S[i] = input();
}

// Define the target characters to count
char* march[] = {"M", "A", "R", "C", "H"};

// Initialize a list to count occurrences of each target character
int march_lis[5] = {0};

// Count the occurrences of each character in the input strings
for (int i = 0; i < N; i++) {
    if (S[i][0] == march[0] || S[i][0] == march[1] || S[i][0] == march[2] || S[i][0] == march[3] || S[i][0] == march[4]) {
        march_lis[march[0] == S[i][0] || march[1] == S[i][0] || march[2] == S[i][0] || march[3] == S[i][0] || march[4] == S[i][0]]++;
    }
}

// Initialize the answer variable to store the result
int ans = 0;

// Calculate the number of ways to choose 3 different characters from the counts
for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
            if (x != y && y != z && z != x) {
                ans += march_lis[x] * march_lis[y] * march_lis[z];
            }
        }
    }
}

// Print the final answer
printf("%d\n", ans);

