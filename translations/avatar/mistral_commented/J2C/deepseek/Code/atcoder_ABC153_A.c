#include <stdio.h>

int main() {
    int h, a, num = 0;

    // Reading two integers from the console
    scanf("%d %d", &h, &a);

    // Using a while loop to simulate the given condition
    while (h > 0) {
        // Subtracting 'a' from 'h' in each iteration
        h -= a;

        // Incrementing the 'num' variable after each successful subtraction
        num++;
    }

    // Printing the final result 'num' to the console
    printf("%d\n", num);

    return 0;
}
