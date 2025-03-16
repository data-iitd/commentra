#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to generate combinations of size i from the set q
void combinations(int *q, int i, int n, int m, int *li, int *p, int *v, int *ans) {
    // If the size of the combination is 0, increment the answer by 2 raised to the power of the size of v
    if (i == 0) {
        *ans += pow(2, *v);
        return;
    }
    
    // Iterating over all possible values of the first element of the combination
    for (int j = 0; j < n; j++) {
        // If the first element of the combination is not in the set q, skip to the next iteration
        if (q[j] == 0) {
            continue;
        }
        
        // Decrementing the first element of the combination
        q[j]--;
        
        // Checking each list in li against the corresponding value in p
        for (int k = 0; k < m; k++) {
            // If the count of common elements is odd and does not match w, break
            if (li[k][0] == 1 && p[k] == 0) {
                break;
            }
        }
        
        // Recursively calling the function to generate combinations of size i - 1 from the set q
        combinations(q, i - 1, n, m, li, p, v, ans);
        
        // Incrementing the first element of the combination
        q[j]++;
    }
}

int main() {
    // Reading the values of n and m from input
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Reading m lists of integers, each containing values after the first element
    int **li = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        li[i] = (int *)malloc((n - 1) * sizeof(int));
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &li[i][j]);
        }
    }
    
    // Reading a tuple p from input
    int *p = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    
    // Creating a set q that contains all unique elements from the lists in li
    int *q = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        q[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            q[li[i][j]] = 1;
        }
    }
    
    // Creating a set r that contains all integers from 1 to n
    int *r = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        r[i] = i + 1;
    }
    
    // Finding the set of values v that are in r but not in q
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (q[i] == 0) {
            v[i] = 1;
        }
    }
    
    // Initializing the answer variable to count valid combinations
    int ans = 0;
    
    // Iterating over all possible sizes of combinations from the set q
    for (int i = 0; i < n; i++) {
        // Generating combinations of size i from the set q
        combinations(q, i, n, m, li, p, v, &ans);
    }
    
    // Printing the final answer
    printf("%d\n", ans);
    
    // Freeing memory
    for (int i = 0; i < m; i++) {
        free(li[i]);
    }
    free(li);
    free(p);
    free(q);
    free(r);
    free(v);
    
    return 0;
}

// END-OF-CODE
