
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <locale.h>
#include <errno.h>
#include <wctype.h>
#include <fenv.h>
#include <complex.h>
#include <stdalign.h>
#include <stdarg.h>
#include <tgmath.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
#include <threads.h>
#include <uchar.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
#include <threads.h>
#include <uchar.h>

int main(int argc, char** argv) {
    // Initialize scanner for reading input
    int N;
    scanf("%d", &N);

    // Allocate memory for the array
    int* arr = malloc(N * sizeof(int));

    // Read the elements of the array
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]); // Read an element
    }

    // Create an instance of the Task class and call its solve method
    Task tsk = new Task();
    printf("%d\n", tsk.solve(arr, N)); // Print the result

    return 0;
}

class Task {
    // Method to solve the problem
    public int solve(int[] arr, int n) {
        // Create a copy of the array for sorting
        int* sorted = malloc(n * sizeof(int));
        memcpy(sorted, arr, n * sizeof(int));
        qsort(sorted, n, sizeof(int), compare); // Sort the copy in ascending order

        long total = (long) n * (n + 1) / 2; // Calculate the total sum of elements from 1 to n^2

        int l = 0, r = n - 1; // Initialize left and right pointers for binary search

        while (l < r) {
            int mid = l + (r - l) / 2; // Calculate the middle index
            int target = sorted[mid]; // The middle element is the target for this iteration

            int cur = 0; // Initialize current sum
            long cnt = 0; // Initialize count of elements less than or equal to target

            long* bit = malloc(2 * n + 2 * sizeof(long)); // Bitmap array for fast counting

            // Initialize the bitmap array
            for (int x = n + 1; x < bit.length; x += x & -x) {
                bit[x]++; // Increment the count for the current position
            }

            // Process each element in the original array
            for (int i = 0; i < n; i++) {
                cur += arr[i] <= target? 1 : -1; // Increment the current sum if the element is less than or equal to target
                for (int x = cur + n + 1; x < bit.length; x += x & -x) {
                    bit[x]++; // Increment the count for the current position
                }
                for (int x = cur + n; x > 0; x -= x & -x) {
                    cnt += bit[x]; // Add the count of elements with sum less than or equal to current sum
                }
            }

            if (cnt >= total / 2 + 1) { // If the count is greater than half the total sum
                r = mid; // Narrow the search range to the left
            } else {
                l = mid + 1; // Narrow the search range to the right
            }
        }

        // Return the middle element as the answer
        return sorted[l];
    }

    // Comparator function for sorting
    static int compare(const void* a, const void* b) {
        return *(int*) a - *(int*) b;
    }
}

