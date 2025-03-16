#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5], r[5];
    int b, last, idx;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
        if (r[i] != 0) {
            b = 10 - r[i];
            // Assuming map is not a standard library in C, we'll use a simple approach
            // Here, we'll just print the value and its remainder for debugging purposes
            printf("Value: %d, Remainder: %d, Add: %d\n", a[i], r[i], b);
        }
    }

    if (b == 0) {
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        printf("%d\n", ans);
        return 0;
    }

    last = b; // Assuming the last value is the maximum remainder value
    for (int i = 0; i < 5; i++) {
        if (a[i] == last) {
            idx = i;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (i != idx) {
            if (a[i] % 10 == 0) {
                ans += a[i];
            } else {
                ans += a[i] + (10 - r[i]);
            }
        }
    }
    ans += last;
    printf("%d\n", ans);

    return 0;
}
