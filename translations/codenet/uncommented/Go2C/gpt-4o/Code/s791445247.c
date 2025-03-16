// by syu
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n % k == 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    return 0;
}

// <END-OF-CODE>
