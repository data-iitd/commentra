#include <stdio.h>

int main() {
    int tc, tcs;
    scanf("%d", &tcs);
    while (tc <= tcs) {
        int a;
        scanf("%d", &a);
        printf("%d\n", a == 0 ? 1 : 0);
        tc++;
    }
    return 0;
}
