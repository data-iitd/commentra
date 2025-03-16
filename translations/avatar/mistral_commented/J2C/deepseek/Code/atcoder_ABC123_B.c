#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5];
    int r[5];
    int b;
    int ans = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;

        if (r[i] != 0) {
            b = 10 - r[i];
            // Assuming TreeMap is not available in C, we will use a simple array to store key-value pairs
            // For simplicity, let's assume we have a function to add key-value pairs
            // addKeyValuePair(b, a[i]);
        }
    }

    if (/* map is empty */ 0) {
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        printf("%d\n", ans);
        return 0;
    }

    int last = /* get last key from map */;
    int idx = 0;

    for (int i = 0; i < 5; i++) {
        if (a[i] == last) {
            idx = i;
            break;
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

