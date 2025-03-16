#include <stdio.h>
#include <stdlib.h>

#define MAX_Q 100

// Arrays to store input values
int a[MAX_Q], b[MAX_Q], c[MAX_Q], d[MAX_Q];

// Variables to store input values
int n = 0;
int m = 0;
int q = 0;

// Variable to store the maximum score
long ans = -100L;

// Function to perform Depth-First Search (DFS)
void dfs(int *list, int size) {
    // If the list size equals n, calculate the score and update ans
    if (size == n) {
        long score = 0L;
        for (int i = 0; i < q; ++i) {
            if (list[b[i]] - list[a[i]] == c[i]) {
                score += d[i];
            }
        }
        if (score > ans) {
            ans = score;
        }
        return;
    }

    // If the list is not empty, continue adding numbers from the last number in the list
    if (size > 0) {
        for (int num = list[size - 1]; num <= m; ++num) {
            list[size] = num;
            dfs(list, size + 1);
        }
    } else {
        // If the list is empty, start with numbers from 1 to m
        for (int num = 1; num <= m; ++num) {
            list[size] = num;
            dfs(list, size + 1);
        }
    }
}

int main() {
    // Read values of n, m, and q
    scanf("%d %d %d", &n, &m, &q);

    // Read the conditions into the arrays
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--; // Adjusting for 0-based index
        b[i]--; // Adjusting for 0-based index
    }

    // Array to store the current combination
    int *list = (int *)malloc(n * sizeof(int));

    // Start the DFS with an empty list
    dfs(list, 0);

    // Print the maximum score found
    printf("%ld\n", ans);

    // Free allocated memory
    free(list);
    
    return 0;
}

// <END-OF-CODE>
