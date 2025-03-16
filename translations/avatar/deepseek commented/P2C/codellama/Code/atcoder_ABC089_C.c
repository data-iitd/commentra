
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read a single line of input
char* input() {
    char* str = (char*)malloc(1000000 * sizeof(char));
    scanf("%[^\n]%*c", str);
    return str;
}

// Function to convert input to an integer
int INT() {
    return atoi(input());
}

// Function to read a map of integers
int* MAP() {
    int* arr = (int*)malloc(1000000 * sizeof(int));
    char* str = input();
    char* token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to convert input to a list of integers
int* LIST() {
    int* arr = (int*)malloc(1000000 * sizeof(int));
    char* str = input();
    char* token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return arr;
}

// Function to create combinations from a list of tuples
int** ZIP(int n) {
    int** arr = (int**)malloc(1000000 * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(1000000 * sizeof(int));
        char* str = input();
        char* token = strtok(str, " ");
        int j = 0;
        while (token != NULL) {
            arr[i][j++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }
    return arr;
}

// Set recursion limit to prevent recursion errors
void set_recursion_limit(int limit) {
    set_recursion_limit(limit);
}

// Define constants
#define INF 1000000000
#define mod 1000000007

// Import numpy for numerical operations
#include <numpy/arrayobject.h>

// Read the number of strings
int N = INT();

// Read the list of strings
char** S = (char**)malloc(1000000 * sizeof(char*));
for (int i = 0; i < N; i++) {
    S[i] = input();
}

// List of characters that can be selected
char* march = "MARC";

// Initialize a list to count occurrences of each character in 'march'
int* march_lis = (int*)malloc(1000000 * sizeof(int));

// Count the occurrences of characters in 'march' in the list of strings
for (int i = 0; i < N; i++) {
    if (S[i][0] == 'M' || S[i][0] == 'A' || S[i][0] == 'R' || S[i][0] == 'C') {
        march_lis[march.index(S[i][0])] += 1;
    }
}

// Initialize the answer variable
int ans = 0;

// Calculate the number of combinations of three elements from march_lis
for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
            ans += march_lis[x] * march_lis[y] * march_lis[z];
        }
    }
}

// Print the final answer
printf("%d", ans);

