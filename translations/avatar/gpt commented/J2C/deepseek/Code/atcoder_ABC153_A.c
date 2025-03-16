#include <stdio.h>
#include <stdlib.h>

int main() {
    int h, a;
    int num = 0;

    // Read two integers from input
    scanf("%d %d", &h, &a);

    // Loop until the health is greater than zero
    while (h > 0) {
        // Decrease health by the amount of damage dealt
        h -= a;
        // Increment the attack counter
        num++;
    }

    // Output the total number of attacks required to reduce health to zero or below
    printf("%d\n", num);

    return 0;
}
