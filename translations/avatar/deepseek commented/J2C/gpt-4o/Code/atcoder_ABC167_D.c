#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LONG_MAX
#define LEN (int)(1e6 + 1)

int main() {
    int N;
    long K;
    
    // Read the number of elements N and the value K
    scanf("%d", &N);
    scanf("%ld", &K);
    
    // Read the array A with N elements, adjusting each element by -1 for 0-based indexing
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i] -= 1; // Adjust for 0-based indexing
    }
    
    // Set to track visited indices
    int *used = (int *)calloc(N, sizeof(int));
    
    // Arrays to store index and position information
    int *idx = (int *)malloc(N * sizeof(int));
    int *pos = (int *)malloc(N * sizeof(int));
    
    // Initialize variables for cycle detection
    int next = 0, cur = 0;
    
    // Detect the cycle in the array A
    while (!used[next]) {
        used[next] = 1; // Mark as visited
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    
    // Calculate the length of the cycle and adjust the position based on K
    long a = (long)cur - idx[next];
    long b = (long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    
    // Adjust the answer if necessary based on the cycle length
    if (b > K) ans = (int)K;
    
    // Output the final position
    printf("%d\n", pos[ans] + 1);
    
    // Free allocated memory
    free(A);
    free(used);
    free(idx);
    free(pos);
    
    return 0;
}

/* <END-OF-CODE> */
