#include <stdio.h> // Include the standard input-output library

int main() {
    int m1, d1, m2, d2; // Declare four integer variables to store month and day values
    scanf("%d%d%d%d", &m1, &d1, &m2, &d2); // Read four integer values from the standard input
    if (m1 != m2) printf("1\n"); // Check if the values of m1 and m2 are not equal, if true print 1
    else printf("0\n"); // If m1 and m2 are equal, print 0
}
