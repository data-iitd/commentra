#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Arrays to store input values
int *a = NULL;
int *b = NULL;
int *c = NULL;
int *d = NULL;

// Variables to store input values
int n = 0;
int m = 0;
int q = 0;

// Variable to store the maximum score
long ans = -100L;

// Function to calculate the score
long calculateScore(int *list) {
    long score = 0L;
    for (int i = 0; i < q; ++i) {
        if (list[b[i]] - list[a[i]] == c[i]) {
            score += d[i];
        }
    }
    return score;
}

// Function to generate combinations
void dfs(int *list, int index) {
    // If the list size equals n, calculate the score and update ans
    if (index == n) {
        long score = calculateScore(list);
        ans = score > ans ? score : ans;
        return;
    }
    
    // If the list is not empty, continue adding numbers from the last number in the list
    if (index > 0) {
        for (int num = list[index - 1]; num <= m; ++num) {
            list[index] = num;
            dfs(list, index + 1);
        }
    } else {
        // If the list is empty, start with numbers from 1 to m
        for (int num = 1; num <= m; ++num) {
            list[index] = num;
            dfs(list, index + 1);
        }
    }
}

int main() {
    // Read values of n, m, and q
    scanf("%d %d %d", &n, &m, &q);
    
    // Initialize arrays to store the conditions
    a = (int *)malloc(q * sizeof(int));
    b = (int *)malloc(q * sizeof(int));
    c = (int *)malloc(q * sizeof(int));
    d = (int *)malloc(q * sizeof(int));
    
    // Read the conditions into the arrays
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        --a[i]; // Adjusting for 0-based index
        --b[i]; // Adjusting for 0-based index
    }
    
    // Start the DFS with an empty list
    int *list = (int *)malloc((n + 1) * sizeof(int));
    dfs(list, 0);
    
    // Print the maximum score found
    printf("%ld\n", ans);
    
    // Free the memory allocated for the arrays
    free(a);
    free(b);
    free(c);
    free(d);
    free(list);
    
    return 0;
}

