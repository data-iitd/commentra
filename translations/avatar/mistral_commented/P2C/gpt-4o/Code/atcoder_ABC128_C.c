#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100
#define MAX_Q 100

int li[MAX_M][MAX_N];
int p[MAX_N];
int q[MAX_Q];
int v[MAX_Q];
int n, m, q_size, v_size;

void generate_combinations(int *arr, int size, int start, int depth, int *current, int current_size) {
    if (depth == 0) {
        // Check the current combination
        int valid = 1;
        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int k = 0; k < current_size; k++) {
                for (int l = 0; l < li[j][0]; l++) {
                    if (current[k] == li[j][l + 1]) {
                        count++;
                    }
                }
            }
            if (count % 2 != p[j]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            // If valid, increment the answer
            ans += (1 << v_size);
        }
        return;
    }

    for (int i = start; i <= size - depth; i++) {
        current[current_size] = arr[i];
        generate_combinations(arr, size, i + 1, depth - 1, current, current_size + 1);
    }
}

int main() {
    // Read input: number of test cases, number of lists, and the lists themselves
    scanf("%d %d", &n, &m);
    memset(li, 0, sizeof(li));
    int q_set[MAX_N] = {0};
    q_size = 0;

    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        li[i][0] = k;
        for (int j = 1; j <= k; j++) {
            scanf("%d", &li[i][j]);
            q_set[li[i][j]] = 1; // Mark the presence of the element
        }
    }

    // Read input: pattern
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    // Create a set of all elements in the lists
    for (int i = 1; i <= n; i++) {
        if (q_set[i]) {
            q[q_size++] = i; // Store unique elements
        }
    }

    // Create a set of numbers from 1 to n (excluding n)
    v_size = 0;
    for (int i = 1; i <= n; i++) {
        if (!q_set[i]) {
            v[v_size++] = i; // Store missing elements
        }
    }

    // Initialize answer to 0
    int ans = 0;

    // Iterate through all possible subsets of q
    for (int i = 0; i <= q_size; i++) {
        int current[MAX_Q];
        generate_combinations(q, q_size, 0, i, current, 0);
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
