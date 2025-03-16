#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *adjacent;
    int count;
} Node;

typedef struct Calculator {
    int k;
    int answer;
    int isCalculate;
    Node *lists;
} Calculator;

void dfs(Calculator *calc, int a, int pre, int *height) {
    int h = 0; // Height of the current node
    for (int i = 0; i < calc->lists[a].count; i++) {
        dfs(calc, calc->lists[a].adjacent[i], a, &h); // Recursively find the height
    }
    // Check if the conditions for incrementing the answer are met
    if (pre > 0 && h == calc->k - 1) {
        h = 0; // Reset height if condition is met
        calc->answer++; // Increment answer
    } else {
        h++; // Increment height
    }
    *height = h; // Return the height
}

int calculate(Calculator *calc) {
    if (!calc->isCalculate) {
        int height = 0;
        dfs(calc, 0, -1, &height); // Start DFS from node 0
        calc->isCalculate = 1; // Mark calculation as done
    }
    return calc->answer; // Return the final answer
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Read the number of elements and threshold value

    Calculator calc;
    calc.k = k;
    calc.answer = 0;
    calc.isCalculate = 0;
    calc.lists = (Node *)malloc(n * sizeof(Node));

    // Initialize the adjacency list
    for (int i = 0; i < n; i++) {
        calc.lists[i].adjacent = (int *)malloc(n * sizeof(int));
        calc.lists[i].count = 0;
    }

    // Read n integers and build the adjacency list
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        value--; // Adjust the value (subtract 1)
        if (i > 0) {
            calc.lists[value].adjacent[calc.lists[value].count++] = i; // Add edge to the adjacency list
        } else if (value > 0) {
            calc.answer++; // Increment answer if the condition is met
        }
    }

    // Calculate the result and print it
    printf("%d\n", calculate(&calc));

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(calc.lists[i].adjacent);
    }
    free(calc.lists);

    return 0;
}

// <END-OF-CODE>
