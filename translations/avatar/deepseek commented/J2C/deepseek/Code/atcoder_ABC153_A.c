#include <stdio.h>

int main() {
    int h, a, num = 0;

    // Reading input for height and amount to subtract
    scanf("%d %d", &h, &a);

    // Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
    while (h > 0) {
        h -= a; // Subtracting 'a' from 'h'
        num++; // Incrementing the counter
    }

    // Printing the result, which is the number of subtractions
    printf("%d\n", num);

    return 0;
}
