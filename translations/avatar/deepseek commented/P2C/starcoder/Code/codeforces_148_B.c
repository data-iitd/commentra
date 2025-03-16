
#include <stdio.h>

int main() {
    int princess, dragon, t, f, c, result, position;

    scanf("%d %d %d %d %d", &princess, &dragon, &t, &f, &c);

    if (dragon <= princess) {
        printf("0\n");
        return 0;
    }

    result = 0;
    position = t * princess;
    position += princess * position / (dragon - princess);

    while (position < c) {
        result++;
        position += princess * position / dragon;
        position += princess * f;
        position += princess * position / (dragon - princess);
    }

    printf("%d\n", result);

    return 0;
}

