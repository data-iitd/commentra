#include <stdio.h>

int main() {
    int candeleIntere, b;
    // Taking two integer inputs and assigning them to candeleIntere and b.
    scanf("%d %d", &candeleIntere, &b);

    // Initializing the sum variable s and the remainder variable restoSciolte to 0.
    int s = 0;
    int restoSciolte = 0;

    // Starting a while loop that continues as long as candeleIntere is greater than 0 or restoSciolte is greater than or equal to b.
    while (candeleIntere > 0 || restoSciolte >= b) {
        // Updating candeleIntere by adding the integer division of restoSciolte by b.
        candeleIntere += restoSciolte / b;

        // Updating restoSciolte to be the remainder of the division of restoSciolte by b.
        restoSciolte %= b;

        // Adding candeleIntere to s.
        s += candeleIntere;

        // Updating restoSciolte by adding the remainder of candeleIntere divided by b.
        restoSciolte += candeleIntere % b;

        // Updating candeleIntere by performing integer division of candeleIntere by b.
        candeleIntere /= b;
    }

    // Printing the value of s after the loop completes.
    printf("%d\n", s);

    return 0;
}

// <END-OF-CODE>
