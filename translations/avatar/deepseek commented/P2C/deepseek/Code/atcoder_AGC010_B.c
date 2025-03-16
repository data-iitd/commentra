#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (sum(a) % (n * (n + 1) / 2)) {
        printf("NO\n");
    } else {
        double k = sum(a) / (n * (n + 1) / 2);
        int a_new[n + 1];
        for (i = 0; i < n; i++) {
            a_new[i] = a[i];
        }
        a_new[n] = a[0];

        if (sum_array(a_new, n + 1) || check_condition(a_new, n, k)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}

int sum(int a[]) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }
    return s;
}

int sum_array(int a[], int size) {
    int s = 0;
    for (int i = 0; i < size; i++) {
        s += a[i];
    }
    return s;
}

int check_condition(int a[], int size, double k) {
    for (int i = 1; i < size; i++) {
        if ((k - a[i] + a[i - 1]) % n != 0 || (k - a[i] + a[i - 1]) / n < 0) {
            return 1;
        }
    }
    return 0;
}
