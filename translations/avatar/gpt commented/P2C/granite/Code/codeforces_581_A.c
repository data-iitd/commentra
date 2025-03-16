
#include <stdio.h>

int main() {
    int a, b;
    // Read two integers from input and unpack them into variables a and b
    scanf("%d %d", &a, &b);

    // Calculate the minimum of a and b, and the half of the difference between the maximum and minimum values
    // Print the minimum value and the calculated half difference
    printf("%d %d\n", a < b? a : b, (a > b? a : b) - (a < b? a : b));

    return 0;
}
// END-OF-CODE