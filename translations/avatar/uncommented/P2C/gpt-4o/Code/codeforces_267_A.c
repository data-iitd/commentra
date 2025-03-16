#include <stdio.h>

int substract(int a, int b) {
    int total = 0;
    if (a > b) {
        while (a > 0 && b > 0) {
            total += a / b;
            a = a % b;
            if (a > 0) {
                total += b / a;
                b = b % a;
            }
        }
    } else if (a < b) {
        while (a > 0 && b > 0) {
            total += b / a;
            b = b % a;
            if (b > 0) {
                total += a / b;
                a = a % b;
            }
        }
    } else { // a == b
        return 1;
    }
    return total;
}

int main() {
    int n;
    scanf("%d", &n);
    int lst[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        lst[i] = substract(a, b);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", lst[i]);
    }
    return 0;
}

// <END-OF-CODE>
