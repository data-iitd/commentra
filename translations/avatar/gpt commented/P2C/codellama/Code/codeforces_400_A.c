#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to read a single line of input and convert it to a tuple of integers
int* value() {
    int* arr = (int*)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
int* values() {
    int* arr = (int*)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

// Function to read a single line of input and return a list of integers
int* inlst() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read a single line of input from stdin and return a list of integers
int* inlsts() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to read a single integer from input
int inp() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a single integer from stdin
int inps() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a single line of input and return it as a string
char* instr() {
    char* str = (char*)malloc(sizeof(char) * 1000);
    scanf("%s", str);
    return str;
}

// Function to read a single line of input and return it as a list of strings
char** stlst() {
    char* str = (char*)malloc(sizeof(char) * 1000);
    scanf("%s", str);
    char** arr = (char**)malloc(sizeof(char*) * 1000);
    int i = 0;
    char* token = strtok(str, " ");
    while (token != NULL) {
        arr[i++] = token;
        token = strtok(NULL, " ");
    }
    return arr;
}

// Helper function to determine if a specific arrangement is possible
bool help(int a, int b, int* l) {
    int* tot = (int*)malloc(sizeof(int) * 1000);
    int j = 0;
    for (int i = 0; i < b; i++) {
        tot[j++] = l[i * a];
    }
    for (int i = 1; i < a; i++) {
        for (int j = 0; j < b; j++) {
            tot[j] += l[i * a + j];
        }
    }
    for (int i = 0; i < b; i++) {
        if (tot[i] == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
void solve() {
    int* tot = (int*)malloc(sizeof(int) * 1000);
    char* x = instr();  // Read the input string
    int* s = (int*)malloc(sizeof(int) * 1000);

    // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }

    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i < 13; i++) {
        if (12 % i == 0) {  // Check if 'i' is a divisor of 12
            if (help(i, 12 / i, s)) {  // Use the helper function to check arrangements
                tot[i] = 1;  // Store valid arrangements as tuples
            }
        }
    }

    // Print the number of valid arrangements
    printf("%d ", tot[1] + tot[2] + tot[3] + tot[4] + tot[6]);

    // Print each valid arrangement in sorted order
    if (tot[1]) {
        printf("1x12 ");
    }
    if (tot[2]) {
        printf("2x6 ");
    }
    if (tot[3]) {
        printf("3x4 ");
    }
    if (tot[4]) {
        printf("4x3 ");
    }
    if (tot[6]) {
        printf("6x2 ");
    }
    printf("\n");
}

// Entry point of the program
int main() {
    int n = inp();  // Read the number of test cases
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}

