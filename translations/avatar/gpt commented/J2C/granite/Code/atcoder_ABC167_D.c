
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables for the cycle detection
    int next = 0, cur = 0; 
    int used[1000001] = {0}; 
    int idx[1000001] = {0}; 
    int pos[1000001] = {0}; 

    // Detect the cycle in the array using the 'used' set
    while (!used[next]) { 
        used[next] = 1; 
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
