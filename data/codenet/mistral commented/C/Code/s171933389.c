
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

// Function to read an array of 4 integers from the standard input
int get_int4(int *a1, int *a2, int *a3, int *a4) {
  // Read 4 integers from the standard input and store them in the given pointers
  scanf("%d %d %d %d", a1, a2, a3, a4);
  // Return 0 to indicate successful execution
  return 0;
}

// Function to read an array of 64-bit integers from the standard input
int fget_array(int64_t *arr, int size) {
    int i;
    // Iterate through the given size and read each 64-bit integer from the standard input and store it in the given array
    for(i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }
    // Return 0 to indicate successful execution
    return 0;
}

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

// Comparator function for qsort to sort an array of 64-bit integers in ascending order
int asc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    // Compare two 64-bit integers and return 1 if aa1 is greater than aa2, 0 if they are equal, and -1 if aa1 is less than aa2
    if(aa1 > aa2) return 1;
    if(aa1 == aa2) return 0;
    return -1;
}

// Comparator function for qsort to sort an array of 64-bit integers in descending order
int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    // Compare two 64-bit integers and return -1 if aa1 is less than aa2, 0 if they are equal, and 1 if aa1 is greater than aa2
    if(aa1 > aa2) return -1;
    if(aa1 == aa2) return 0;
    return 1;
}

#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

struct range {
    int start;
    int end;
};

// Function to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
int lower_bound(int64_t *arr, struct range r, int64_t key) {
    int low = r.start;;
    int high = r.end;
    // Binary search to find the index of the first element greater than or equal to the given key in the sorted array arr, within the given range r
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    // Return the index of the first element greater than or equal to the given key, or the size of the array if no such element exists
    return low + 1;
}

int main(void) {
    int x, y, z, rank;
    // Read 4 integers x, y, z, and rank from the standard input
    get_int4(&x, &y, &z, &rank);
    static int64_t xrr[NUM_MAX]; // Declare an array xrr of size NUM_MAX to store the first array of 64-bit integers
    static int64_t yrr[NUM_MAX]; // Declare an array yrr of size NUM_MAX to store the second array of 64-bit integers
    static int64_t zrr[NUM_MAX]; // Declare an array zrr of size NUM_MAX to store the third array of 64-bit integers
    // Read the three arrays of 64-bit integers from the standard input using the function fget_array()
    fget_array(xrr, x);
    fget_array(yrr, y);
    fget_array(zrr, z);
    int64_t min_sum = VAL_MAX+1; // Initialize min_sum with a value larger than any possible sum
    int64_t max_sum = 0; // Initialize max_sum with an initial value of 0
    int i, j;
    // Iterate through the third array zrr and update min_sum and max_sum accordingly
    for(i = 0; i < z; i++) {
        min_sum = min(min_sum, zrr[i]);
        max_sum += zrr[i];
    }

    static int64_t pair[NUM2_MAX]; // Declare an array pair of size NUM2_MAX to store the sum of each pair of elements from the first and second arrays
    int idx = 0; // Initialize an index variable idx to 0
    // Iterate through the first array xrr and the second array yrr, and compute the sum of each pair, storing it in the array pair
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            pair[idx++] = xrr[i] + yrr[j];
        }
    }
    // Sort the array pair in ascending order using the qsort() function and the asc() comparator function
    qsort(pair, idx, sizeof(int64_t), asc);
    // Update min_sum and max_sum with the sum of the first and last elements in the sorted array pair, respectively
    min_sum += pair[0];
    max_sum += pair[idx-1];

    static int cache[NUM_MAX]; // Declare an array cache of size NUM_MAX to store the index of the last element less than or equal to the current pivot in the sorted array pair, for each pivot in the third array zrr
    static int cnt_map[NUM_MAX]; // Declare an array cnt_map of size NUM_MAX to store the number of elements in the sorted array pair less than or equal to the current pivot, for each pivot in the third array zrr
    static int64_t ans[RANK_MAX]; // Declare an array ans of size RANK_MAX to store the answer for each rank
    int size = x*y*z; // Compute the size of the array pair
    int64_t prev = min_sum; // Initialize prev with the initial value of min_sum
    int r; // Initialize a loop variable r with an initial value of rank
    // Iterate through the ranks from rank down to 1, and find the answer for each rank using binary search
    for(r = rank; r >= 1; r--) {
        int64_t low = prev-1; // Initialize the lower bound of the binary search with prev-1
        int64_t high = max_sum+1; // Initialize the upper bound of the binary search with max_sum+1
        // Binary search to find the index of the first element greater than or equal to the current rank in the sorted array ans, using the lower_bound() function
        while(low + 1 < high) {
            int64_t mid = (low + high)/2;
            // Compute the number of elements in the sorted array pair less than or equal to the current pivot, for each pivot in the third array zrr
            for(i = 0; i < z; i++) {
                int64_t pivot = zrr[i];
                struct range r = {cache[i]-1, idx}; // Define the range r for the current pivot
                int tmp = lower_bound(pair, r, mid-pivot); // Find the index of the first element greater than or equal to mid-pivot in the sorted array pair, within the range r
                cnt_map[i] = tmp; // Store the number of elements in the sorted array pair less than or equal to the current pivot, for the current pivot
            }
            // Check if the total number of elements in the sorted array pair less than or equal to the current pivot, for all pivots in the third array zrr, is greater than or equal to the size of the array pair minus the current rank
            if(sum(cnt_map, z) >= size-r) {
                // If so, update prev with mid and continue the outer loop
                low = mid;
            } else {
                // Otherwise, update high with mid and continue the inner loop
                high = mid;
            }
        }
        // Store the index of the first element greater than or equal to the current rank in the sorted array ans
        ans[r-1] = low;
        // If the index found is equal to max_sum, break the outer loop as there is no solution for the current rank
        if(low == max_sum) break;
        // Update prev with the index found
        prev = low;
    }
    // Print the answer for each rank, except for the last rank which may not have a solution
    for(i = 0; i < rank; i++) {
        printf("%lld\n", (ans[i]==0) ? max_sum : ans[i]);
    }

    return 0;
}