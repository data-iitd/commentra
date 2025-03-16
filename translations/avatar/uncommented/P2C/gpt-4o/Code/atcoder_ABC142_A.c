#include <stdio.h>

int next_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int n = next_int();
    int t = 0;

    for (int i = 0; i < n; i++) {
        if ((i + 1) & 1) {
            t += 1;
        }
    }

    printf("%f\n", (double)t / n);
    return 0;
}

// <END-OF-CODE>
