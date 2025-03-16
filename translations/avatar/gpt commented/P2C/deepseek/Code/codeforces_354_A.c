#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, L, R, QL, QR;
    scanf("%d %d %d %d %d", &n, &L, &R, &QL, &QR);

    int W[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }

    int sum_el[n + 1];
    sum_el[0] = 0;

    for (int i = 1; i <= n; i++) {
        sum_el[i] = W[i - 1] + sum_el[i - 1];
    }

    int answer = QR * (n - 1) + sum_el[n] * R;

    for (int i = 1; i <= n; i++) {
        int energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]);

        if (i > (n - i)) {
            energy += (i - (n - i) - 1) * QL;
        } else if ((n - i) > i) {
            energy += ((n - i) - i - 1) * QR;
        }

        if (energy < answer) {
            answer = energy;
        }
    }

    printf("%d\n", answer);

    return 0;
}

