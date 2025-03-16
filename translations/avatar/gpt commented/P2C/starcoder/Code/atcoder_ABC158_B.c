#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single integer from input
int I() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read multiple integers from input and return them as a map
int MI() {
    int n, i;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return a;
}

// Function to read multiple integers from input and return them as a list
int LI() {
    int n, i;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return a;
}

int main() {
    // Define the modulo constant
    int mod = 1000000007;
    
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    
    // Initialize the answer variable
    int ans = 0;
    
    // Calculate how many complete cycles of (A + B) fit into N
    int rep = N / (A + B);
    
    // Add the total items of type A from the complete cycles to the answer
    ans += rep * A;
    
    // Calculate the remaining items after complete cycles
    int res = N - rep * (A + B);
    
    // Add the minimum of remaining items or A to the answer
    ans += min(res, A);
    
    // Print the final answer
    printf("%d\n", ans);
}

// 