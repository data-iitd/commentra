
#include <stdio.h>

int main() {
    int h, a, sho, am;

    // Read two integers from input: h (height) and a (height per shoe)
    scanf("%d %d", &h, &a);

    // Calculate the number of shoes needed by performing integer division
    sho = h / a;

    // Calculate the remaining height after accounting for full shoes
    am = h % a;

    // If there is any remaining height, we need one additional shoe
    if (am!= 0) {
        sho += 1;  // Increment the shoe count by 1 for the remaining height
    }

    // Print the total number of shoes required
    printf("%d", sho);

    return 0;
}
