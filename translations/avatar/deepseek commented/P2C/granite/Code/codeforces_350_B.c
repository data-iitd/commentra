

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Taking an integer input `n` which represents the number of elements.
    int t[n + 1], a[n + 1], cnt[n + 1];
    for (int i = 0; i <= n; i++) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);  // Taking a list of integers `t` as input.
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);  // Taking another list of integers `a` as input.
        cnt[a[i]]++;  // Counting the occurrences of each element in `a` and storing them in `cnt`.
    }
    int ans[n + 1], len = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {  // Checking if `t[i]` is 1, indicating the start of a potential cycle.
            int crt[n + 1], j = 0;
            crt[j++] = i;  // Starting a list `crt` with `i`.
            int x = a[i];  // Initializing `x` with the value at index `i` in `a`.
            while (cnt[x] == 1) {  // Finding the cycle by following the `a` list until reaching an element whose count is not 1.
                crt[j++] = x;
                x = a[x];
            }
            if (j > len) {  // Updating `ans` if the length of `crt` is greater than the length of `ans`.
                len = j;
                for (int k = 0; k < j; k++) {
                    ans[k] = crt[k];
                }
            }
        }
    }
    // Reversing `ans` to get the correct order of elements in the cycle.
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        int temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
    }
    // Printing the length of `ans` and the elements of `ans`.
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
