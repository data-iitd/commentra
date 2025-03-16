
#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((a == 5 && b == 5) || (a == 5 && c == 5) || (b == 5 && c == 5)) {
        if (a + b + c == 17) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}
