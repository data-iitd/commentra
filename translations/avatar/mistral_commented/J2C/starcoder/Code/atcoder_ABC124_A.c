#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a, b, sum = 0;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a--;
        } else {
            sum += b;
            b--;
        }
    }
    printf("%d\n", sum);
    return EXIT_SUCCESS;
}

