
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int min_value = a < b? a : b;
    int max_value = a > b? a : b;

    printf("%d %d\n", min_value, (max_value - min_value) / 2);

    return 0;
}

