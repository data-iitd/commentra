
#include <stdio.h>

int main() {
    int n, d, nums[100000], result = 0, a = 0;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i < n; i++) {
        a = (nums[i - 1] - nums[i]);
        if (a >= 0) {
            result += a / d + 1;
            nums[i] += (a / d + 1) * d;
        }
    }
    printf("%d\n", result);
    return 0;
}
// END-OF-CODE