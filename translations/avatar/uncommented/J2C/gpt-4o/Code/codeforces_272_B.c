#include <stdio.h>

int rec(long x) {
    int answer = 0;
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k)) != 0) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[33] = {0}; // Initialize array to zero

    for (int i = 0; i < n; i++) {
        long x;
        scanf("%ld", &x);
        a[rec(x)]++;
    }

    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }

    printf("%ld\n", (long)answer);
    return 0;
}

// <END-OF-CODE>
