#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Step 3: Declare variables to store input values
    int a, b, c, d, e, k;

    // Step 4: Read input values from the user
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &k);

    // Step 5: Calculate the difference between e and a and check if it is less than or equal to k
    if (e - a <= k) {
        printf("Yay!\n");
    } else {
        printf(":(\n");
    }

    // Step 7: Return 0 to indicate successful execution
    return 0;
}
