#include <stdio.h>

int main() {
    int r, D, x;
    scanf("%d %d %d", &r, &D, &x);
    for (int i = 2; i <= 11; i++) {
        int result = (int)((pow(r, i - 1)) * (x + (D / (1 - r))) - (D / (1 - r)));
        printf("%d\n", result);
    }
    return 0;
}
