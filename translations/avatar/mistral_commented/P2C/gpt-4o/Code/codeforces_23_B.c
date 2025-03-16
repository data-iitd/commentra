#include <stdio.h>

int main() {
    // Take an integer input from the user and assign it to the variable n
    int n;
    scanf("%d", &n);

    // Iterate n times
    for (int i = 0; i < n; i++) {
        // Take an integer input from the user and assign it to the variable a
        int a;
        scanf("%d", &a);

        // Check if a is less than 2
        if (a < 2) {
            // If a is less than 2, print 0
            printf("0\n");
            // Move to the next iteration of the loop
            continue;
        }

        // If a is not less than 2, check if it is greater than or equal to 2
        if (a >= 2) {
            // If a is greater than or equal to 2, print a - 2
            printf("%d\n", a - 2);
        }
    }

    return 0;
}
// <END-OF-CODE>
