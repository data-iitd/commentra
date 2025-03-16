
#include <stdio.h>

int main(void) {
    int princess, dragon, t, f, c, result, position;

    scanf("%d %d %d %d %d", &princess, &dragon, &t, &f, &c);

    result = 0;
    position = t * princess;

    while (position < c) {
        result++;
        position += princess * position / dragon;
        position += princess * f;
        position += princess * position / (dragon - princess);
    }

    printf("%d\n", result);

    return 0;
}

