#include <stdio.h>

int main() {
    // Declare variables for health, damage, and number of attacks
    int h, a, num = 0;

    // Read the initial health and damage dealt per attack
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

// <END-OF-CODE>
