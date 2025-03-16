#include <stdio.h>

int main() {
    // Declare five integer variables to hold input values
    int a, b, c, d, e;

    // Read five integers from standard input
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // Create an array containing the input integers
    int al[] = {a, b, c, d, e};

    // Iterate over the array to find the first occurrence of zero
    for (int n = 0; n < 5; n++) {
        // Check if the current element is zero
        if (al[n] == 0) {
            // Print the index (1-based) of the first zero found and exit the loop
            printf("%d\n", n + 1);
            break;
        }
    }

    return 0;
}
