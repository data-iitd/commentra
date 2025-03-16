
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n, k, z;
    scanf("%d %d", &n, &k);
    n++;
    if (n % k!= 0) {
        z = k - n % k;
    }
    printf("%d\n", n + z);
    return EXIT_SUCCESS;
}

