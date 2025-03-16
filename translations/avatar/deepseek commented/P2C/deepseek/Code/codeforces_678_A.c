#include <stdio.h>

int main() {
    int vamshi, z;
    scanf("%d %d", &vamshi, &z);

    // Calculating the result using integer division and addition
    int result = (vamshi / z + 1) * z;

    // Printing the result
    printf("%d\n", result);

    return 0;
}

