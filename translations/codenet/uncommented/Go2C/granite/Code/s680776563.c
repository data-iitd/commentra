
#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (B - A == C - B) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
