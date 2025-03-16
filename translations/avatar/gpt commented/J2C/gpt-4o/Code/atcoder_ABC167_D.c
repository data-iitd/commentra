#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LONG_MAX
#define LEN (1000000 + 1)

int main() {
    // Initialize variables
    int N;
    long K;
    
    // Read the number of elements N and the long value K
    scanf("%d %ld", &N, &K);
    
    // Initialize the array A to store the input values
    int *A = (int *)malloc(N * sizeof(int));
    
    // Read N integers into the array A and adjust values to be zero-indexed
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--; // Adjust to zero-indexed
    }
    
    // Set to track used indices and arrays to store index and position
    int *used = (int *)calloc(N, sizeof(int));
    int *idx = (int *)malloc(N * sizeof(int));
    int *pos = (int *)malloc(N * sizeof(int));
    
    // Initialize variables for the cycle detection
    int next = 0, cur = 0;
    
    // Detect the cycle in the array using the 'used' array
    while (!used[next]) {
        used[next] = 1; // Mark as used
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    
    // Calculate the lengths of the cycle and the position of the next element
    long a = (long)cur - idx[next];
    long b = (long)idx[next];
    
    // Calculate the answer based on the cycle length and K
    int ans = (int)((10000 * a + K - b) % a + b);
    
    // If b is greater than K, set ans to K
    if (b > K) ans = (int)K;
    
    // Output the result, adjusting for 1-based indexing
    printf("%d\n", pos[ans] + 1);
    
    // Free allocated memory
    free(A);
    free(used);
    free(idx);
    free(pos);
    
    return 0;
}

// <END-OF-CODE>
