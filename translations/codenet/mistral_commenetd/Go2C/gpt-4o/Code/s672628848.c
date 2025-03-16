#include <stdio.h>

int main() {
    // Declare variables a, b, c, d, and e of type int
    int a, b, c, d, e;

    // Read input values for variables a, b, c, d, and e from the standard input
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // Create an array named al with the values of variables a, b, c, d, and e
    int al[] = {a, b, c, d, e};

    // Iterate through each element i in the array al starting from the index 0
    for (int n = 0; n < 5; n++) {
        // Check if the current element i is equal to 0
        if (al[n] == 0) {
            // Print the index number n+1 as output
            printf("%d\n", n + 1);
            // Break the loop as soon as the first zero element is found
            break;
        }
    }

    return 0;
}
// <END-OF-CODE>
