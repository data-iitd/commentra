#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Taking an integer input `n` which represents the number of elements.
    
    int *t = (int *)malloc((n + 1) * sizeof(int));
    int *a = (int *)malloc((n + 1) * sizeof(int));
    int *cnt = (int *)calloc(n + 1, sizeof(int));  // Initializing `cnt` with zeros.
    int *ans = (int *)malloc((n + 1) * sizeof(int));  // To store the answer.
    int ans_len = 0;  // To keep track of the length of `ans`.

    // Taking a list of integers `t` as input.
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    // Taking another list of integers `a` as input.
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // Counting the occurrences of each element in `a` and storing them in `cnt`.
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    // Iterating over the range from 1 to `n` to find cycles starting from each element.
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {  // Checking if `t[i]` is 1, indicating the start of a potential cycle.
            int crt_len = 0;  // Length of the current cycle.
            int x = a[i];  // Initializing `x` with the value at index `i` in `a`.
            int *crt = (int *)malloc((n + 1) * sizeof(int));  // To store the current cycle.

            // Finding the cycle by following the `a` list until reaching an element whose count is not 1.
            while (cnt[x] == 1) {
                crt[crt_len++] = x;  // Append `x` to `crt`.
                x = a[x];  // Move to the next element in the cycle.
            }

            // Updating `ans` if the length of `crt` is greater than the length of `ans`.
            if (crt_len > ans_len) {
                ans_len = crt_len;
                for (int j = 0; j < crt_len; j++) {
                    ans[j] = crt[j];
                }
            }
            free(crt);  // Free the memory allocated for `crt`.
        }
    }

    // Reversing `ans` to get the correct order of elements in the cycle.
    for (int i = 0; i < ans_len / 2; i++) {
        int temp = ans[i];
        ans[i] = ans[ans_len - 1 - i];
        ans[ans_len - 1 - i] = temp;
    }

    // Printing the length of `ans` and the elements of `ans`.
    printf("%d\n", ans_len);
    for (int i = 0; i < ans_len; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    // Free allocated memory
    free(t);
    free(a);
    free(cnt);
    free(ans);

    return 0;
}

// <END-OF-CODE>
