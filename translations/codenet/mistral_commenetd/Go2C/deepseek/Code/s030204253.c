#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    float a[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                float temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    float na[n - 1];
    for (int j = 2; j < n; j++) {
        na[j - 2] = a[j];
    }

    na[n - 2] = (a[0] + a[1]) / 2;

    a = na;

    printf("%.6f\n", a[0]);

    return 0;
}
