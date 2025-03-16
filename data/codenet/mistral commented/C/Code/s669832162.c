
#include <stdio.h> // Include the standard input/output library

int main() { // Start of the main function
    int m1, d1, m2, d2; // Declare four integer variables to store months and days

    // Read four integers from the standard input
    scanf("%d%d%d%d", &m1, &d1, &m2, &d2);

    // Check if the first two months are equal or not
    if (m1 != m2) {
        // If the months are not equal, print "1" to the standard output
        printf("1\n");
    } else {
        // If the months are equal, print "0" to the standard output
        printf("0\n");
    }
}