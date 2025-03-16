#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from the input
int nextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Main function
int main() {
    // Read the first three integers from the input
    int a = nextInt();
    int b = nextInt();
    int c = nextInt();

    // Check if the condition is true
    if (a + b >= c) {
        // If true, print "Yes" to the output
        printf("Yes\n");
    } else {
        // If false, print "No" to the output
        printf("No\n");
    }

    // End of code
    return 0;
}

// <END-OF-CODE>
