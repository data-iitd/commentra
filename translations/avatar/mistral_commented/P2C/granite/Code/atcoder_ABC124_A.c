
#include <stdio.h>

int main() {
    int a, b, c = 0;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < 2; i++) {
        c += (a > b)? a-- : b--;
    }
    printf("%d", c);
    return 0;
}
// END-OF-CODE