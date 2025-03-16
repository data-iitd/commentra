
#include <stdio.h>

// Use readline for faster input
#define input(x) scanf("%d", &x)

// Function to read a single integer from input
int I() {
    int x;
    input(x);
    return x;
}

// Function to read multiple integers from input and return them as a map
int *MI() {
    int x, y, *arr;
    input(x);
    input(y);
    arr = (int *)malloc(x * sizeof(int));
    for (int i = 0; i < x; i++) {
        input(arr[i]);
    }
    return arr;
}

// Function to read multiple integers from input and return them as a list
int *LI() {
    int x, y, *arr;
    input(x);
    input(y);
    arr = (int *)malloc(x * sizeof(int));
    for (int i = 0; i < x; i++) {
        input(arr[i]);
    }
    return arr;
}

int main() {
    // Define the modulo constant
    int mod = 1000000007;
    
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N, A, B;
    input(N);
    input(A);
    input(B);
    
    // Initialize the answer variable
    int ans = 0;
    
    // Calculate how many complete cycles of (A + B) fit into N
    int rep = N / (A + B);
    
    // Add the total items of type A from the complete cycles to the answer
    ans += rep * A;
    
    // Calculate the remaining items after complete cycles
    int res = N - rep * (A + B);
    
    // Add the minimum of remaining items or A to the answer
    ans += (res < A) ? res : A;
    
    // Print the final answer
    printf("%d\n", ans);
    
    return 0;
}

