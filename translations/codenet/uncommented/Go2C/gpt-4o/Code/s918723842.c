#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a < b) ? b : a;
}

int main() {
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);

    int A = max(H, W);
    printf("%d\n", (N + A - 1) / A);

    return 0;
}

/* <END-OF-CODE> */
