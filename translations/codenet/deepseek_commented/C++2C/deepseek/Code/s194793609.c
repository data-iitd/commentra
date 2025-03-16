#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // 1. Reading the input size `n`

    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]); // 2. Reading the array elements
    }

    long long abs_a[n];
    for (int i = 0; i < n; i++) {
        abs_a[i] = llabs(a[i]); // 3. Creating a copy of the array with absolute values
    }

    long long ans = 0; // 4. Calculating the sum of absolute values
    long long min = abs_a[0];
    for (int i = 0; i < n; i++) {
        ans += abs_a[i];
        if (min > abs_a[i]) {
            min = abs_a[i];
        }
    }

    int num_negative = 0; // 5. Counting the number of negative elements
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            num_negative++;
        }
    }

    if (num_negative % 2) { // 6. Adjusting the sum based on the number of negative elements
        ans -= min * 2;
    }

    printf("%lld\n", ans); // 7. Outputting the result
}

