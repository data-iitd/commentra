#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Variable to hold the sum
    int sum = k;
    int ans = 1;

    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
