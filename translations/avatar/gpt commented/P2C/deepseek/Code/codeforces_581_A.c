#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int min_val = a < b ? a : b;
    int max_val = a > b ? a : b;
    int diff = max_val - min_val;
    printf("%d %d\n", min_val, diff / 2);
    return 0;
}

