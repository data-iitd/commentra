#include <stdio.h>

// Function to read an integer
int I() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a map of integers
int *MI() {
    int *arr = (int *)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

// Function to read a list of integers
int *LI() {
    int *arr = (int *)malloc(sizeof(int) * 2);
    scanf("%d %d", &arr[0], &arr[1]);
    return arr;
}

// Main function
int main() {
    int mod = 1000000007;  // Modulo value
    int N, A, B;  // Reading N, A, and B
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
    
    return 0;
}

