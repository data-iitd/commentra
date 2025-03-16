
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
    // Importing the itertools module for combinatorial functions
    #include <itertools.h>
    
    // Reading the values of n and m from input
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Reading m lists of integers, each containing values after the first element
    int **li = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        int size;
        scanf("%d", &size);
        li[i] = (int *)malloc((size + 1) * sizeof(int));
        for (int j = 0; j < size; j++) {
            scanf("%d", &li[i][j]);
        }
    }
    
    // Reading a tuple p from input
    int p[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    
    // Creating a set q that contains all unique elements from the lists in li
    int *q = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < li[i][0] + 1; j++) {
            q[li[i][j]] = 1;
        }
    }
    
    // Creating a set r that contains all integers from 1 to n
    int *r = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i < n + 1; i++) {
        r[i] = 1;
    }
    
    // Finding the set of values v that are in r but not in q
    int *v = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i < n + 1; i++) {
        if (q[i] == 0 && r[i] == 1) {
            v[i] = 1;
        }
    }
    
    // Initializing the answer variable to count valid combinations
    int ans = 0;
    
    // Iterating over all possible sizes of combinations from the set q
    for (int i = 0; i < n + 1; i++) {
        // Generating combinations of size i from the set q
        int **combs = itertools_combinations(q, i);
        for (int j = 0; j < itertools_size(combs); j++) {
            // Checking each list in li against the corresponding value in p
            bool valid = true;
            for (int k = 0; k < m; k++) {
                int count = 0;
                for (int l = 1; l < li[k][0] + 1; l++) {
                    if (combs[j][li[k][l]] == 1) {
                        count++;
                    }
                }
                if (count % 2!= p[k]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                // If all checks passed, increment the answer by 2 raised to the power of the size of v
                ans += pow(2, itertools_size(v));
            }
        }
        itertools_free(combs);
    }
    
    // Printing the final answer
    printf("%d\n", ans);
    
    // Freeing dynamically allocated memory
    for (int i = 0; i < m; i++) {
        free(li[i]);
    }
    free(li);
    free(q);
    free(r);
    free(v);
    
    return 0;
}

// Entry point of the program
int main() {
    return 0;
}

