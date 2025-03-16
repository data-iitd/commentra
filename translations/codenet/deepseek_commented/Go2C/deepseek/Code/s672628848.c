#include <stdio.h>

int main() {
    // Declare five integer variables to hold input values
    int a, b, c, d, e;

    // Read five integers from the standard input and assign them to the variables
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // Create an array containing the five integers
    int al[] = {a, b, c, d, e};

    // Iterate over the array using a for loop
    for (int n = 0; n < 5; n++) {
        // Check if the current element is equal to 0
        if (al[n] == 0) {
            // Print the position of the element (1-based index) and break out of the loop
            printf("%d\n", n + 1);
            break;
        }
    }

    return 0;
}
