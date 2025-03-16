#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *req = (int *)malloc(n * sizeof(int));
    int *pre = (int *)malloc(m * sizeof(int));
    
    // Read elements into req
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    // Read elements into pre
    for (int i = 0; i < m; i++) {
        scanf("%d", &pre[i]);
    }
    
    int i = n - 1, j = m - 1; // Initialize indices i and j
    int ans = 0; // Initialize ans to store the result
    
    // Implement the logic to find the number of elements in req that are greater than the corresponding elements in pre
    while (i >= 0 && j >= 0) {
        if (req[i] > pre[j]) { // If the element in req is greater than the element in pre
            ans++; // Increment ans
        } else {
            j--; // Decrement j to check the next element in pre
        }
        i--; // Decrement i in each iteration
    }
    
    // Print the result which is the sum of ans and the remaining elements in req
    printf("%d\n", ans + i + 1);
    
    // Free allocated memory
    free(req);
    free(pre);
    
    return 0;
}
