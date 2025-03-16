#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int as[n+1];
    int bs[n];

    for (int i = 0; i <= n; i++) {
        scanf("%d", &as[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &bs[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a = as[i];
        int b = bs[i];
        if (a <= b) {
            sum += a;
            b -= a;
            if (i+1 <= n) {
                int an = as[i+1];
                if (an <= b) {
                    sum += an;
                    as[i+1] = 0;
                } else {
                    sum += b;
                    as[i+1] -= b;
                }
            }
        } else {
            sum += b;
        }
    }
    printf("%d\n", sum);

