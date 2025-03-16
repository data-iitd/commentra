#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(long*)a - *(long*)b);
}

int main() {
    int n;
    long k;
    
    // Read the number of elements in the array
    scanf("%d", &n);
    
    // Read the value of k
    scanf("%ld", &k);
    
    // Initialize an array to hold the input numbers
    long arr[n];
    
    // Read n long integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }
    
    // Sort the array to facilitate the processing of elements
    qsort(arr, n, sizeof(long), compare);
    
    // Initialize a counter to keep track of valid elements
    int count = 0;
    
    // Create a hash set to store unique elements that meet the criteria
    // For simplicity, we use a dynamically allocated array to simulate a hash set
    long *set = (long *)malloc(n * sizeof(long));
    int set_size = 0;
    
    // Iterate through the sorted array to apply the conditions
    for (int i = 0; i < n; i++) {
        // Check if the current element is not divisible by k
        if (arr[i] % k != 0) {
            count++; // Increment count for valid element
            // Add the element to the set if it's not already present
            bool found = false;
            for (int j = 0; j < set_size; j++) {
                if (set[j] == arr[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                set[set_size++] = arr[i];
            }
        }
        // Check if the current element is divisible by k and its corresponding k-factor is not in the set
        else if (arr[i] % k == 0 && arr[i] / k % k != 0 && !binary_search(set, set_size, arr[i] / k)) {
            count++; // Increment count for valid element
            // Add the element to the set if it's not already present
            bool found = false;
            for (int j = 0; j < set_size; j++) {
                if (set[j] == arr[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                set[set_size++] = arr[i];
            }
        }
    }
    
    // Output the final count of valid elements
    printf("%d\n", count);
    
    // Free the allocated memory for the set
    free(set);
    
    return 0;
}

// A simple binary search function to check if an element is in the set
bool binary_search(long *set, int size, long value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (set[mid] == value) {
            return true;
        } else if (set[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
