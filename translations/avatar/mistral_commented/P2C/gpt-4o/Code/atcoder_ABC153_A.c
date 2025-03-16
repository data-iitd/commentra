#include <stdio.h>

int main() {
    int h, a;
    scanf("%d %d", &h, &a);
    // Assign the first and second elements of the input string to variables h and a, respectively

    int sho = h / a;
    // Calculate the quotient of h by a and assign the result to the variable sho

    int am = h % a;
    // Calculate the remainder of the division of h by a and assign the result to the variable am

    if (am != 0) {
        // Check if the remainder is equal to zero
        // If not, execute the following block of code
        sho += 1;
        // Increment the value of the variable sho by one
    }

    printf("%d\n", sho);
    // Print the value of the variable sho

    return 0;
}
