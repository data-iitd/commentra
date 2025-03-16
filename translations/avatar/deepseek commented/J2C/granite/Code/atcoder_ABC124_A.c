

#include <stdio.h>

int main() {
    // Create a Scanner object to read input from the user
    int a, b, sum = 0; // Initialize sum to 0, this will store the sum of the two numbers

    // Read two integers from the input
    scanf("%d %d", &a, &b);

    // Loop runs twice, each time adding the larger of the two numbers to sum
    // and decrementing that number by 1
    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a = a - 1;
        } else {
            sum += b;
            b = b - 1;
        }
    }

    // Print the final sum to the console
    printf("%d", sum);

    return 0;
}
