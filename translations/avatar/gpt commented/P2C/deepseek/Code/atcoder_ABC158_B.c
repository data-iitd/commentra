#include <stdio.h>

#define mod 1000000007

// Function to read a single integer from input
int I() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read multiple integers from input and return them as a map
void MI(int *N, int *A, int *B) {
    scanf("%d %d %d", N, A, B);
}

// Function to read multiple integers from input and return them as a list
void LI(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void main() {
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N, A, B;
    MI(&N, &A, &B);
    
    // Initialize the answer variable
    int ans = 0;
    
    // Calculate how many complete cycles of (A + B) fit into N
    int rep = N / (A + B);
    
    // Add the total items of type A from the complete cycles to the answer
    ans += rep * A;
    
    // Calculate the remaining items after complete cycles
    int res = N - rep * (A + B);
    
    // Add the minimum of remaining items or A to the answer
    ans += res < A ? res : A;
    
    // Print the final answer
    printf("%d\n", ans);
}

