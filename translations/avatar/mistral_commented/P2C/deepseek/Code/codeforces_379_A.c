#include <stdio.h>

int main() {
    int candeleIntere, b, s = 0, restoSciolte = 0;

    // Get the number of candles 'candeleIntere' and the box size 'b' from user input
    scanf("%d %d", &candeleIntere, &b);

    // Continue the loop as long as there are still candles or the remaining candles are greater than or equal to the box size
    while (candeleIntere > 0 || restoSciolte >= b) {

        // Calculate the number of full boxes of candles that can be put in the box
        candeleIntere += restoSciolte / b;

        // Update the remaining candles
        restoSciolte %= b;

        // Add the number of candles in the current box to the sum
        s += candeleIntere;

        // Update the remaining candles by adding the remainder of the current box
        restoSciolte += candeleIntere % b;

        // Update the number of candles to be put in the next box
        candeleIntere /= b;
    }

    // Print the final sum
    printf("%d\n", s);

    return 0;
}
