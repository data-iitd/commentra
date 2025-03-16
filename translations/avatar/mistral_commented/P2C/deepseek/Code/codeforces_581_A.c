#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int min_value = a < b ? a : b;
    int max_value = a > b ? a : b;

    int difference = max_value - min_value;
    int average_difference = difference / 2;

    printf("%d %d\n", min_value, average_difference);

    return 0;
}
