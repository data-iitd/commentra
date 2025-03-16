#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int l = 0, c = 1;
    int a;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == l)
            c += 1;
        else
            c = 1;
        l = a;
    }

    if (c + k > n)
        printf("%d\n", n - c);
    else
        printf("-1\n");

    return 0;
}

