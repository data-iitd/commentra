#include <stdio.h>
#include <math.h>

int main() {
    long startTime = clock();
    int n;
    scanf("%d", &n);
    long div = (long)pow(10, 9) + 7;
    long A[n];
    long ans = 0;

    for (int i = 0; i < n; i++) {
        scanf("%ld", &A[i]);
    }

    for (int i = 0; i < 60; i++) {
        long a = 0;
        long count1 = 0;

        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count1++;
            }
        }

        a = a + count1 * (n - count1);
        for (int j = 0; j < i; j++) {
            a = (a << 1) % div;
        }

        ans += a;
        ans %= div;
    }

    printf("%ld\n", ans);
    long endTime = clock();
    return 0;
}

// <END-OF-CODE>
