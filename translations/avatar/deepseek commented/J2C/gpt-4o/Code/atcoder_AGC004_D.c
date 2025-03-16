#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *children;
    int count;
} Node;

typedef struct Calculator {
    int k;
    int answer;
    int isCalculate;
    Node *lists;
} Calculator;

void dfs(Calculator *calc, int a, int pre, int *height) {
    int h = 0; // Variable to store the height of the tree
    for (int i = 0; i < calc->lists[a].count; i++) {
        int child = calc->lists[a].children[i];
        dfs(calc, child, a, &h); // Recursively calculate the height
    }
    if (pre > 0 && h == calc->k - 1) {
        h = 0; // Reset height if condition is met
        calc->answer++; // Increment answer if condition is met
    } else {
        h++; // Increment height otherwise
    }
    *height = h; // Return the height
}

int calculate(Calculator *calc) {
    if (!calc->isCalculate) {
        int height = 0;
        dfs(calc, 0, -1, &height); // Start DFS from the root node
        calc->isCalculate = 1; // Set the flag to true
    }
    return calc->answer; // Return the calculated answer
}

int main() {
    int n, k; // Number of elements and parameter k
    scanf("%d %d", &n, &k); // Read the number of elements and parameter k

    // Initialize the Calculator object
    Calculator calc;
    calc.k = k;
    calc.answer = 0;
    calc.isCalculate = 0;
    calc.lists = (Node *)malloc(n * sizeof(Node));

    // Initialize each list in the lists
    for (int i = 0; i < n; i++) {
        calc.lists[i].children = (int *)malloc(n * sizeof(int));
        calc.lists[i].count = 0;
    }

    // Read input values and build relationships
    for (int i = 0; i < n; i++) {
        int j;
        scanf("%d", &j);
        j--; // Adjust by subtracting 1
        if (i > 0) {
            calc.lists[j].children[calc.lists[j].count++] = i; // Add relationship between elements
        } else if (j > 0) {
            calc.answer++; // Increment answer if condition is met
        }
    }

    // Calculate the result and print it
    printf("%d\n", calculate(&calc));

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(calc.lists[i].children);
    }
    free(calc.lists);

    return 0;
}

// <END-OF-CODE>
