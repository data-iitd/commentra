
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#define MAX_N 100000
#define MAX_K 100000

typedef struct {
    int n;
    int k;
    int answer;
    bool isCalculate;
    int lists[MAX_N][MAX_N];
} Calculator;

// Function to read input values using Scanner
void readInput(Calculator *calculator) {
    int n; // Number of elements
    int k; // Some parameter k
    int i; // Loop variable
    int j; // Loop variable
    int a; // Element
    int b; // Element

    // Read input values using Scanner
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        a--;
        calculator->lists[a][0] = 1; // Add relationship between elements
        if (0 < i) {
            calculator->lists[a][i] = 1; // Add relationship between elements
        } else if (0 < a) {
            calculator->answer++; // Increment answer if condition is met
        }
    }
    calculator->n = n;
    calculator->k = k;
}

// Function to calculate the result using DFS
void calculate(Calculator *calculator) {
    if (!calculator->isCalculate) {
        dfs(calculator, 0, 0); // Start DFS from the root node
        calculator->isCalculate = true; // Set the flag to true
    }
}

// DFS method to traverse through the lists
int dfs(Calculator *calculator, int a, int pre) {
    int h = 0; // Variable to store the height of the tree
    for (int i = 0; i < calculator->n; i++) {
        if (calculator->lists[a][i] == 1) {
            h = max(h, dfs(calculator, i, a)); // Recursively calculate the height
        }
    }
    if (0 < pre && h == calculator->k - 1) {
        h = 0; // Reset height if condition is met
        calculator->answer++; // Increment answer if condition is met
    } else {
        h++; // Increment height otherwise
    }
    return h; // Return the height
}

// Main function
int main(int argc, char *argv[]) {
    Calculator calculator; // Calculator object

    // Read input values using Scanner
    readInput(&calculator);

    // Calculate the result using DFS
    calculate(&calculator);

    // Print the calculated answer
    printf("%d\n", calculator.answer);

    return EXIT_SUCCESS;
}

