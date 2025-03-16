#include <stdio.h>

int main() {
    int K, X;
    scanf("%d %d", &K, &X);
    if (500 * K >= X) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

