
#include <stdio.h>
#include <stdlib.h>

// Arrays to store input values
int a[100];
int b[100];
int c[100];
int d[100];

// Variables to store input values
int n;
int m;
int q;

// Variable to store the maximum score
long long ans = -100000000000000000LL;

// Function to generate combinations using Depth-First Search (DFS)
void dfs(int *list, int size) {
    // If the list size equals n, calculate the score and update ans
    if (size == n) {
        long long score = 0LL;
        for (int i = 0; i < q; ++i) {
            if (list[b[i]] - list[a[i]] == c[i]) {
                score += d[i];
            }
        }
        ans = ans > score? ans : score;
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
    }

    // Start the DFS with an empty list
    int *list = (int *)malloc(sizeof(int) * n);
    dfs(list, 0);
    free(list);

    // Print the maximum score found
    printf("%lld\n", ans);

    return 0;
}
