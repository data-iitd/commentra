/*
 * FileName:     the_number_of_inversions_fix
 * CreatedDate:  2020-06-05 16:25:10 +0900
 * LastModified: 2020-07-06 22:22:35 +0900
 */

#include <stdio.h>
#include <stdlib.h>
#define unko 1e12  // Define a large constant to act as a sentinel value

// Function to merge two halves of an array and count inversions
long int sort(long int *a, int left, int middle, int right) {
    // Create temporary arrays for left and right halves
    long int l_arr[middle-left+1], r_arr[right-middle+1];
    long int cnt = 0;  // Initialize inversion count

    // Copy data to temporary arrays
    for(int i = 0; i < middle - left; i++) l_arr[i] = a[i + left];
    for(int i = 0; i < right - middle; i++) r_arr[i] = a[i + middle];

    // Add sentinel values to the end of the temporary arrays
    l_arr[middle-left] = unko;
    r_arr[right-middle] = unko;

    int l = 0, r = 0;  // Initialize pointers for left and right arrays

    // Merge the two halves back into the original array
    for(int i = 0; i < right - left; i++) {
        if(l_arr[l] <= r_arr[r]) {
            a[left + i] = l_arr[l++];  // Take from left array
        } else {
            a[left + i] = r_arr[r++];  // Take from right array
            cnt += middle - left - l;   // Count inversions
        }
    }
    return cnt;  // Return the count of inversions
}

// Function to recursively divide the array and count inversions
long int merge(long int *a, int left, int right) {
    if(left + 1 < right) {
        int middle = (left + right) / 2;  // Find the middle point
        long int x1 = merge(a, left, middle);  // Count inversions in the left half
        long int x2 = merge(a, middle, right);  // Count inversions in the right half
        long int x3 = sort(a, left, middle, right);  // Count inversions while merging
        return x1 + x2 + x3;  // Return total count of inversions
    } else {
        return 0;  // Base case: no inversions if the segment has one or no elements
    }
}

int main(void) {
    int n; 
    scanf("%d", &n);  // Read the number of elements
    long int *a = malloc(n * sizeof(long int));  // Allocate memory for the array

    // Read the elements into the array
    for(int i = 0; i < n; i++) scanf("%ld", a + i);

    // Call the merge function and print the number of inversions
    printf("%ld\n", merge(a, 0, n));

    free(a);  // Free the allocated memory
    return 0;  // Return success
}
