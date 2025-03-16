#include <stdio.h>

// Function to read an integer
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a map of integers
void MI(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read a list of integers
void LI(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
void main() {
    const int mod = 1000000007;  // Modulo value
    int N, A, B;
    MI(&N, &A);
    MI(&B, &A);  // Reading N, A, and B
    int ans = 0;  // Initializing the result variable
    
    // Calculating the number of complete cycles of A + B within N
    int rep = N / (A + B);
    
    // Updating the result with the number of complete cycles multiplied by A
    ans += rep * A;
    
    // Calculating the remaining days after the complete cycles
    int res = N - rep * (A + B);
    
    // Updating the result with the minimum of the remaining days and A
    ans += (res < A) ? res : A;
    
    // Printing the final result
    printf("%d\n", ans);
}
