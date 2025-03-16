#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5];
    int r[5];
    int b;
    int idx;
    int ans = 0;

    // Step 2: Reading input and storing remainders
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
        if (r[i] != 0) {
            b = 10 - r[i];
            // Assuming we need to store the value and the adjustment needed for each element
            // This part is not directly translatable to C without additional data structures
        }
    }

    // Step 3: Handling edge cases
    int max_value = 0;
    for (int i = 0; i < 5; i++) {
        if (r[i] != 0) {
            max_value = a[i];
            idx = i;
            break;
        }
    }
    if (max_value == 0) {
        for (int i = 0; i < 5; i++) {
            ans += a[i];
        }
        printf("%d\n", ans);
        return 0;
    }

    // Step 4: Finding the maximum and adjusting values
    for (int i = 0; i < 5; i++) {
        if (a[i] == max_value && i != idx) {
            if (a[i] % 10 == 0) {
                ans += a[i];
            } else {
                ans += a[i] + (10 - r[i]);
            }
        }
    }
    ans += max_value;
    printf("%d\n", ans);

    return 0;
}
