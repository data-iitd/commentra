
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stdint.h>

int main(int argc, char **argv) {
    // Read the number of queries
    int q;
    scanf("%d", &q);

    // Initialize answers and sums
    int ans[2] = {0, 0};
    long long sum_b = 0;
    long long sum_p1 = 0;
    long long sum_p2 = 0;

    // Initialize two heaps for managing two groups of numbers
    long long p1[100000];
    long long p2[100000];
    int p1_len = 0;
    int p2_len = 0;

    // Process each query
    for (int i = 0; i < q; i++) {
        // Read the query line and convert it to a list of integers
        int ql[3];
        scanf("%d %d %d", &ql[0], &ql[1], &ql[2]);

        // If the query type is 2, perform a specific operation
        if (ql[0] == 2) {
            // If both heaps are of equal length, calculate and print the result based on p2
            if (p1_len == p2_len) {
                printf("%lld %lld\n", p2[0], sum_p1 - p1_len * p2[0] + p2_len * p2[0] - sum_p2 + sum_b);
            } else {
                // If p1 is longer, calculate and print the result based on p1
                printf("%lld %lld\n", p1[0], sum_p1 - p1_len * p1[0] + p2_len * p1[0] - sum_p2 + sum_b);
            }
        } else {
            // If the query type is 1, update the heaps and sums
            sum_b += ql[2];  // Add the third element of the query to the sum_b

            // If p1 is empty, push the new value into p1
            if (p1_len == 0) {
                p1[p1_len++] = ql[1];
                sum_p1 += ql[1];
            }
            // If the new value is greater than or equal to the smallest in p1, push it to p1
            else if (p1[0] <= ql[1]) {
                p1[p1_len++] = ql[1];
                sum_p1 += ql[1];
            } else {
                // Otherwise, push the negative of the new value into p2 (to maintain max-heap behavior)
                p2[p2_len++] = -ql[1];
                sum_p2 += ql[1];
            }

            // Balance the heaps if p1 has fewer elements than p2
            if (p1_len < p2_len) {
                long long k = p2[--p2_len];  // Pop the largest from p2
                p1[p1_len++] = -k;  // Push it to p1 (as positive)
                sum_p2 += k;  // Update sum_p2
                sum_p1 -= k;  // Update sum_p1
            }

            // Balance the heaps if p1 has more than one extra element compared to p2
            if (p1_len - 1 > p2_len) {
                long long k = p1[--p1_len];  // Pop the smallest from p1
                p2[p2_len++] = -k;  // Push it to p2 (as negative)
                sum_p1 -= k;  // Update sum_p1
                sum_p2 += k;  // Update sum_p2
            }
        }
    }

    return 0;
}
