
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // 1. Reading the input number of elements (n)
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int)); // 2. Reading the elements into a slice (a)
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *b = (int *)malloc(n * sizeof(int)); // 3. Creating a slice (b) to store the longest increasing subsequence
    int b_len = 0;
    for (int i = 0; i < n; i++) { // 4. Finding the longest increasing subsequence
        int x = 0;
        int y = b_len;
        while (x < y) {
            int m = (x + y) / 2;
            if (b[m] < a[i]) {
                x = m + 1;
            } else {
                y = m;
            }
        }
        if (x == b_len) {
            b[b_len] = a[i];
            b_len++;
        } else {
            b[x] = a[i];
        }
    }

    printf("%d\n", b_len); // 5. Outputting the length of the longest increasing subsequence

    free(a);
    free(b);

    return 0;
}
