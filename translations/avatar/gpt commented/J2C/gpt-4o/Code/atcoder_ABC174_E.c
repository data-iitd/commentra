#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *logsLength;
    int n;
    int k;
} Solution;

int canCut(int mid, int *logsLength, int n, int k) {
    for (int i = 0; i < n; i++) {
        k -= (logsLength[i] + mid - 1) / mid - 1; // Calculate the number of cuts needed
    }
    return k >= 0; // Return true if we can make the cuts within the limit of k
}

int main() {
    // Read the number of logs and the value of k
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Allocate memory for the lengths of the logs
    int *logsLength = (int *)malloc(n * sizeof(int));
    
    // Read the lengths of the logs into an array
    for (int i = 0; i < n; i++) {
        scanf("%d", &logsLength[i]);
    }
    
    // Initialize binary search bounds
    int min = 1, max = 1000000000 + 1000; 
    
    // Perform binary search to find the minimum possible length
    while (min < max) {
        int mid = (min + max) / 2;
        
        // Check if it's possible to cut the logs with the current mid length
        if (canCut(mid, logsLength, n, k)) 
            max = mid; // If possible, search in the lower half
        else 
            min = mid + 1; // Otherwise, search in the upper half
    }
    
    // Output the minimum length found
    printf("%d\n", min);
    
    // Free allocated memory
    free(logsLength);
    
    return 0;
}

// <END-OF-CODE>
