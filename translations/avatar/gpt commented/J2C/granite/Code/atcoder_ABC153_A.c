
#include <stdio.h>

int main() {
    int h, a, num = 0;
    scanf("%d %d", &h, &a);
    for (int i = 1; h > 0; i++) {
        h = h - a;
        num++;
    }
    printf("%d", num);
    return 0;
}
