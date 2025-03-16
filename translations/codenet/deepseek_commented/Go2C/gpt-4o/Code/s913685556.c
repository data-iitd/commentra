#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int A, B;
    
    // Read two integers A and B
    scanf("%d %d", &A, &B);
    
    // Calculate the maximum value among A+B, A-B, and A*B
    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    
    // Print the maximum value
    printf("%d\n", mx);
    
    return 0;
}

// <END-OF-CODE>
