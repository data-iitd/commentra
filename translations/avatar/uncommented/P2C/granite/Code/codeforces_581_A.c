
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", (a < b)? a : b, (a > b)? (a - b) / 2 : (b - a) / 2);
    return 0;
}
// END-OF-CODE