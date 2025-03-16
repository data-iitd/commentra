#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    printf("%d\n", mx);

    return 0;
}
