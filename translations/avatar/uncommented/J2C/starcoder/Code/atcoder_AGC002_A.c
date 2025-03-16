#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > 0) {
        printf("Positive\n");
    } else if (b >= 0) {
        printf("Zero\n");
    } else if ((b - a + 1) % 2 == 0) {
        printf("Positive\n");
    } else {
        printf("Negative\n");
    }
    return 0;
}
