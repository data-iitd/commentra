#include <stdio.h>
#include <stdlib.h>

// Custom input function
int input( ) {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read an integer
int I( ) {
    return input();
}

// Function to read multiple integers
int *MI( ) {
    int *arr = (int *)malloc(sizeof(int) * input());
    for (int i = 0; i < input(); i++) {
        arr[i] = input();
    }
    return arr;
}

// Function to read a list of integers
int *LI( ) {
    int *arr = (int *)malloc(sizeof(int) * input());
    for (int i = 0; i < input(); i++) {
        arr[i] = input();
    }
    return arr;
}

// Main function
int main( ) {
    // Setting the modulus value
    int mod = 1000000007;

    // Reading input values: N, A, and B
    int N = I();
    int A = I();
    int B = I();

    // Initializing the answer variable to 0
    int ans = 0;

    // Calculating the number of repetitions
    int rep = N / (A + B);

    // Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A;

    // Calculating the remaining number of blocks
    int res = N - rep * (A + B);

    // Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, A);

    // Printing the final answer
    printf("%d\n", ans);

    // End of code
    return 0;
}


Translate the above Python code to Java and end with comment "