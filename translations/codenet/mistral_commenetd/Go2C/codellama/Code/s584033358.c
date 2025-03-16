
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d\n", &n, &k);
    if (k <= (n+n%2)/2) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

// 