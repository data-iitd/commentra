#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);
    long ans[n];
    long *q = (long *)malloc(n * sizeof(long));
    int q_size = 0;

    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);

        // Remove elements from the queue that are less than or equal to t
        while (q_size > 0 && q[0] <= t) {
            for (int j = 1; j < q_size; j++) {
                q[j - 1] = q[j];
            }
            q_size--;
        }

        // Check if the queue size is less than or equal to b
        if (q_size <= b) {
            // Calculate the answer and add it to the queue
            ans[i] = (q_size == 0) ? t : q[q_size - 1];
            ans[i] += d;
            q[q_size++] = ans[i];
        } else {
            // If the queue size exceeds b, set the answer to -1
            ans[i] = -1;
        }
    }

    // Print the answers for all test cases
    for (int i = 0; i < n; i++) {
        printf("%ld ", ans[i]);
    }

    // Free the allocated memory for the queue
    free(q);
    return 0;
}
