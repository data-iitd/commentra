#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    const int N = 1e5 + 5;
    long cnt[21] = {0};

    // Count the occurrences of each value shifted by 10
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        cnt[value + 10]++;
    }

    long res = 0;

    // Calculate the number of pairs that sum up to 20
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    // Special case for pairs where both elements are the same (i.e., i = 10)
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    // Output the result
    printf("%ld\n", res);

    return 0;
}
