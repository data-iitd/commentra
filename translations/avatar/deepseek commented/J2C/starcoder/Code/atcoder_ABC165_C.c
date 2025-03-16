#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arrays to store input values
int a[100000];
int b[100000];
int c[100000];
int d[100000];

// Variables to store input values
int n = 0;
int m = 0;
int q = 0;

// Variable to store the maximum score
long ans = -100L;

// Depth-First Search (DFS) function to generate combinations
void dfs(int list[], int size) {
    // If the list size equals n, calculate the score and update ans
    if (size == n) {
        long score = 0L;
        for (int i = 0; i < q; ++i) {
            if (list[b[i]] - list[a[i]] == c[i]) {
                score += d[i];
            }
        }
        ans = max(ans, score);
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
    scanf("%d %d %d", &n, &m, &q);
    
    // Read the conditions into the arrays
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    
    // Start the DFS with an empty list
    int list[100000];
    dfs(list, 0);
    
    // Print the maximum score found
    printf("%ld\n", ans);
    
    return 0;
}

