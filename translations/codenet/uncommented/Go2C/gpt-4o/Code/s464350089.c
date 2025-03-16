#include <stdio.h>

#define MOD 1000000007

int main() {
    int h, n;
    scanf("%d %d", &h, &n);
    int a = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a += x;
    }

    if (h > a) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}

// <END-OF-CODE>
