#include <stdio.h>

int main() {
    int h, a;
    scanf("%d %d", &h, &a);

    int sho = h / a;
    int am = h % a;

    if (am != 0) {
        sho += 1;
    }

    printf("%d\n", sho);

    return 0;
}
