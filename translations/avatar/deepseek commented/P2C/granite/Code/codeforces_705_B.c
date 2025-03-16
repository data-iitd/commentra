

#include <stdio.h>

int main() {
    // Read the number of elements in the list `w`
    int n;
    scanf("%d", &n);

    // Read the list of integers `w`
    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    // Initialize the variable `c` to 2
    int c = 2;

    // Loop through each element `i` in the list `w`
    for (int i = 0; i < n; i++) {
        // Check if `i` is equal to 1
        if (w[i] == 1) {
            // Print the current value of `c`
            printf("%d\n", c);
        }
        // Check if `i` is even
        else if (w[i] % 2 == 0) {
            // Toggle the value of `c` between 2 and 3-c (i.e., 1 or 3)
            c = 3 - c;
            // Print the new value of `c`
            printf("%d\n", c);
        }
        // If `i` is odd
        else {
            // Print the current value of `c`
            printf("%d\n", c);
        }
    }

    return 0;
}
