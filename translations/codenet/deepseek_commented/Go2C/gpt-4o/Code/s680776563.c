#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Main function: Entry point of the program.
int main() {
    int A, B, C;
    A = readInt();
    B = readInt();
    C = readInt();
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    // Check if the difference between consecutive integers is the same
    if (B - A == C - B) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

<<<<<<< HEAD
// Utility functions for various operations (not used in this specific example)
=======
// Utility functions for various operations (not used in this specific case)
>>>>>>> 98c87cb78a (data updated)
int IntMax(int a, int b) {
    return (a > b) ? a : b;
}

int IntMin(int a, int b) {
    return (a < b) ? a : b;
}

int IntGcd(int a, int b) {
    if (b == 0) return a;
    return IntGcd(b, a % b);
}

int IntAbs(int a) {
    return (a < 0) ? -a : a;
}

// Note: The utility functions are included for completeness but are not used in the main logic.

