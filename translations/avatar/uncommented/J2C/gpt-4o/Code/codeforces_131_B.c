#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long cnt[21] = {0}; // Initialize array to zero

    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        cnt[input + 10]++;
    }

    long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    printf("%ld\n", res);
    return 0;
}

// <END-OF-CODE>
