#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LONG_MAX

int main() {
    // Initialize scanner for input
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Initialize the array A to store the input values
    int A[N];
    
    // Read N integers into the array A and adjust values to be zero-indexed
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--;
    }
    
    // Set to track used indices and arrays to store index and position
    bool used[N];
    int idx[N], pos[N];
    
    // Initialize variables for the cycle detection
    int next = 0, cur = 0;
    
    // Detect the cycle in the array using the 'used' set
    while (!used[next]) {
        used[next] = true;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    
    // Calculate the lengths of the cycle and the position of the next element
    long a = (long) cur - idx[next];
    long b = (long) idx[next];
    
    // Calculate the answer based on the cycle length and K
    int ans = (int) ((10000 * a + K - b) % a + b);
    
    // If b is greater than K, set ans to K
    if (b > K) ans = (int) K;
    
    // Output the result, adjusting for 1-based indexing
    printf("%d\n", pos[ans] + 1);
    
    return 0;
}

