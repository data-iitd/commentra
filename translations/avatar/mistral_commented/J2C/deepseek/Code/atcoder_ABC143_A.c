#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;

    // Reading two integers from the console
    scanf("%d %d", &a, &b);

    // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
    c = a - b * 2;

    // If the value of 'c' is negative, set it to zero
    if (c < 0) {
        c = 0;
    }

    // Print the value of 'c' to the console
    printf("%d\n", c);

    return 0;
}
