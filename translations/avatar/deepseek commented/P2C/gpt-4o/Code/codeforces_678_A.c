#include <stdio.h>

int main() {
    int vamshi, z;

    // Taking input from the user
    scanf("%d %d", &vamshi, &z);

    // Calculating the result using integer division and addition
    int result = (vamshi / z + 1) * z;

    // Printing the result
    printf("%d\n", result);

    return 0;
}

// <END-OF-CODE>
