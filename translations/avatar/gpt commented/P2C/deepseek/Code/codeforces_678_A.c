#include <stdio.h>

int main() {
    int vamshi, z;
    scanf("%d %d", &vamshi, &z);

    // Calculate the smallest multiple of z that is greater than or equal to vamshi
    // This is done by performing integer division of vamshi by z, adding 1, and then multiplying by z
    int result = ((vamshi / z) + 1) * z;

    // Print the result
    printf("%d\n", result);

    return 0;
}
