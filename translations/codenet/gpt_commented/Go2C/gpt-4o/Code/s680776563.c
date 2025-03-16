#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from input
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to check if the difference between B and A is equal to the difference between C and B
void checkDifference(int A, int B, int C) {
    if (B - A == C - B) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    // Read three integers A, B, and C from input
    int A = readInt();
    int B = readInt();
    int C = readInt();
    
    // Check the differences
    checkDifference(A, B, C);
    
    return 0;
}

/* <END-OF-CODE> */
