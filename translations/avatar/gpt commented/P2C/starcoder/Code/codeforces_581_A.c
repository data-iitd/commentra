#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d", min(a, b), (max(a, b) - min(a, b)) / 2);
    return 0;
}
