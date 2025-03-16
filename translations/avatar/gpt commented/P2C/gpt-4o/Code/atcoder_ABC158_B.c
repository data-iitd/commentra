#include <stdio.h>

#define MOD 1000000007

// Function to read a single integer from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read multiple integers from input
void readInts(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

int main() {
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N, A, B;
    readInts(&N, &A, &B);
    
    // Initialize the answer variable
    long long ans = 0;
    
    // Calculate how many complete cycles of (A + B) fit into N
    int rep = N / (A + B);
    
    // Add the total items of type A from the complete cycles to the answer
    ans += (long long)rep * A;
    
    // Calculate the remaining items after complete cycles
    int res = N - rep * (A + B);
    
    // Add the minimum of remaining items or A to the answer
    ans += (res < A) ? res : A;
    
    // Print the final answer
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
