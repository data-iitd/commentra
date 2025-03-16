
#include <stdio.h>

int main() {
    int h, a, sho, am;

    // Step 1: Taking input from the user
    scanf("%d %d", &h, &a);

    // Step 2: Calculating the number of times 'a' fits into 'h' and the remainder
    sho = h / a;
    am = h % a;

    // Step 3: Checking if there is a remainder and incrementing the count if necessary
    if (am!= 0) {
        sho += 1;
    } else {
        // Do nothing
    }

    // Step 4: Printing the result
    printf("%d", sho);

    return 0;
}

