#include <stdio.h>

int main() {
    int princess, dragon, t, f, c;
    scanf("%d %d %d %d %d", &princess, &dragon, &t, &f, &c);
    int result = 0;
    int position = t * princess;
    position += princess * position / (dragon - princess);
    while (position < c) {
        result++;
        position += princess * position / dragon;
        position += princess * f;
        position += princess * position / (dragon - princess);
    }
    printf("%d", result);
    return 0;
}
