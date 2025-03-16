#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint> // uint64_t

// Macro definitions for maximum and minimum
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

// Function to read four integers from standard input
int get_int4(int *a1, int *a2, int *a3, int *a4) {
    scanf("%d %d %d %d", a1, a2, a3, a4);
    return 0;
}

// Function to read an array of int64_t from standard input
int fget_array(int64_t *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    return 0;
}

// Constants defining maximum sizes for arrays and ranks
#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

// Comparison function for ascending order used in qsort
int asc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return 1;
    if(aa1 == aa2) return 0;
    return -1;
}

// Comparison function for descending order used in qsort
int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return -1;
    if(aa1 == aa2) return 0;
    return 1;
}

// Constants defining maximum values for calculations
#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

// Structure to represent a range with start and end indices
struct range {
    int start;
    int end;
};

// Function to find the lower bound index of a key in a sorted array
int lower_bound(int64_t *arr, struct range r, int64_t key) {
    int low = r.start;
    int high = r.end;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low + 1; // Return the index of the first element greater than key
}

// Main function
int main(void) {
    // Variables to hold input values and rank
    int x, y, z, rank;
    get_int4(&x, &y, &z, &rank); // Read the dimensions and rank

    // Arrays to hold input values
    static int64_t xrr[NUM_MAX];
    static int64_t yrr[NUM_MAX];
    static int64_t zrr[NUM_MAX];

    // Read the arrays from input
    fget_array(xrr, x);
    fget_array(yrr, y);
    fget_array(zrr, z);

    // Initialize min and max sums
    int64_t min_sum = VAL_MAX + 1;
    int64_t max_sum = 0;

    // Calculate minimum and maximum values from zrr
    int i, j;
    for(i = 0; i < z; i++) min_sum = min(min_sum, zrr[i]);
    for(i = 0; i < z; i++) max_sum = max(max_sum, zrr[i]);

    // Create an array to hold the sums of pairs from xrr and yrr
    static int64_t pair[NUM2_MAX];
    int idx = 0;

    // Calculate all possible sums of pairs from xrr and yrr
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            pair[idx++] = xrr[i] + yrr[j];
        }
    }

    // Sort the pair array in ascending order
    qsort(pair, idx, sizeof(int64_t), asc);

    // Update min and max sums with the smallest and largest pair sums
    min_sum += pair[0];
    max_sum += pair[idx - 1];

    // Arrays for caching and counting
    static int cache[NUM_MAX];
    static int cnt_map[NUM_MAX];
    static int64_t ans[RANK_MAX];

    // Calculate the size of the combined array
    int size = x * y * z;
    int64_t prev = min_sum;
    int r;

    // Iterate to find the rank-th largest sum
    for(r = rank; r >= 1; r--) {
        int64_t low = prev - 1;
        int64_t high = max_sum + 1;

        // Binary search to find the appropriate sum
        while(low + 1 < high) {
            int64_t mid = (low + high) / 2;
            int cnt = 0;

            // Count how many sums are less than or equal to mid
            for(i = 0; i < z; i++) {
                int64_t pivot = zrr[i];
                struct range r = {cache[i] - 1, idx};
                int tmp = lower_bound(pair, r, mid - pivot);
                cnt_map[i] = tmp;
                cnt += tmp;
            }

            // Adjust the search range based on the count
            if(cnt <= size - r) {
                memcpy(cache, cnt_map, sizeof(int) * z);
                low = mid;
            } else {
                high = mid;
            }
        }

        // Store the found sum in the answer array
        ans[r - 1] = low;
        if(low == max_sum) break; // Stop if we reach the maximum sum
        prev = low; // Update previous sum for the next iteration
    }

    // Print the results for each rank
    for(i = 0; i < rank; i++) {
        printf("%lld\n", (ans[i] == 0) ? max_sum : ans[i]);
    }

    return 0; // Return success
}

