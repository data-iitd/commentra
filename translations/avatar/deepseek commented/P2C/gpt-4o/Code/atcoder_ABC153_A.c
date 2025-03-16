#include <stdio.h>

int main() {
    // Step 1: Taking input from the user
    int h, a;
    scanf("%d %d", &h, &a);

    // Step 2: Calculating the number of times 'a' fits into 'h' and the remainder
    int sho = h / a;
    int am = h % a;

    // Step 3: Checking if there is a remainder and incrementing the count if necessary
    if (am != 0) {
        sho += 1;
    }

    // Step 4: Printing the result
    printf("%d\n", sho);

    return 0;
}

// <END-OF-CODE>
