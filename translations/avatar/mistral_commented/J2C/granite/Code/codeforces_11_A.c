

#include <stdio.h>

int main() {
    int n, d, a, result = 0;
    scanf("%d %d", &n, &d);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i < n; i++) {
        a = nums[i - 1] - nums[i];
        if (a >= 0) {
            result += a / d + 1;
            nums[i] += (a / d + 1) * d;
        }
    }
    printf("%d", result);
    return 0;
}

