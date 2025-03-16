#include <stdio.h>

int main() {
    int n, a;

    // Read an integer input from the user, which represents the number of test cases
    scanf("%d", &n);

    // Loop through each test case
    for (int i = 0; i < n; i++) {
        // Read an integer input for the current test case
        scanf("%d", &a);

        // Check if the input number is less than 2
        if (a < 2) {
            // If true, print 0 as the output for this case
            printf("0\n");
        }

        // Check if the input number is greater than or equal to 2
        if (a >= 2) {
            // If true, print the result of (a - 2)
            printf("%d\n", a - 2);
        }
    }

    return 0;
}
