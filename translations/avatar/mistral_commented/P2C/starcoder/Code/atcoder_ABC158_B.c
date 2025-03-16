#include <stdio.h>
#include <stdlib.h>

// Function to read an integer
int I(void) {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read multiple integers
void MI(int *arr, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

// Function to read a list of integers
int *LI(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return arr;
}

// Function to calculate the number of repetitions
int rep(int N, int A, int B) {
    return N / (A + B);
}

// Function to calculate the number of blocks that can be fully covered by A and B in one repetition
int full(int rep, int A) {
    return rep * A;
}

// Function to calculate the number of blocks that can be covered by A in the remaining blocks
int min(int res, int A) {
    return res < A? res : A;
}

// Main function
int main(void) {
    // Setting the modulus value
    int mod = 1000000007;

    // Reading input values: N, A, and B
    int N = I(), A = I(), B = I();

    // Initializing the answer variable to 0
    int ans = 0;

    // Calculating the number of repetitions
    int rep = rep(N, A, B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += full(rep, A);

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, A);

    // Printing the final answer
    printf("%d\n", ans);

    // Returning from main
    return 0;
}

// 