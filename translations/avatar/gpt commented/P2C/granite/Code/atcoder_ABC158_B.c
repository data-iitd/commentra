
#include <stdio.h>

// Define the modulo constant
#define MOD 100000007

// Function to read a single integer from input
int I(){
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read multiple integers from input and return them as a map
int* MI(){
    int N;
    scanf("%d", &N);
    int* A = new int[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    return A;
}

// Function to read multiple integers from input and return them as a list
int* LI(){
    int N;
    scanf("%d", &N);
    int* A = new int[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    return A;
}

int main(){
    // Read input values: N (total items), A (items of type A), B (items of type B)
    int N = I(), A = I(), B = I();
    
    // Initialize the answer variable
    int ans = 0;
    
    // Calculate how many complete cycles of (A + B) fit into N
    int rep = N / (A + B);
    
    // Add the total items of type A from the complete cycles to the answer
    ans += rep * A;
    
    // Calculate the remaining items after complete cycles
    int res = N - rep * (A + B);
    
    // Add the minimum of remaining items or A to the answer
    ans += (res < A? res : A);
    
    // Print the final answer
    printf("%d\n", ans);
    
    return 0;
}

// End of code