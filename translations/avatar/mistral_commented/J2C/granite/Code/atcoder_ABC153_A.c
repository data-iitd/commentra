
#include <stdio.h>

int main() {
    int h, a, num = 0;
    scanf("%d %d", &h, &a);
    while (h > 0) {
        h -= a;
        num++;
    }
    printf("%d", num);
    return 0;
}
// END-OF-CODE