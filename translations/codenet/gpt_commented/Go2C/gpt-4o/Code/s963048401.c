#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
<<<<<<< HEAD

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
=======
#define MAX_N 100000

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b;
>>>>>>> 98c87cb78a (data updated)
}

// Function to perform binary search
int binarySearch(int *arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
<<<<<<< HEAD
    // Read the number of elements
    int n;
    scanf("%d", &n);
    
    // Initialize an array to hold the integers
    int *as = (int *)malloc(n * sizeof(int));
    
    // Read n integers from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }
    
    // Initialize an array to hold the unique sorted integers
    int *xs = (int *)malloc(n * sizeof(int));
    int uniqueCount = 0;
    
    // Iterate through the input integers
    for (int j = 0; j < n; j++) {
        // Use binary search to find the position to insert the current integer
        int idx = binarySearch(xs, uniqueCount, as[j]);
        
        // If the index is equal to the count of unique integers, append the integer
        if (idx == uniqueCount) {
            xs[uniqueCount] = as[j];
            uniqueCount++;
        } else {
            // Otherwise, replace the existing integer at the found index
            xs[idx] = as[j];
        }
    }
    
    // Print the number of unique integers found
    printf("%d\n", uniqueCount);
    
    // Free allocated memory
    free(as);
    free(xs);
    
=======
    int n;
    scanf("%d", &n); // Read the number of elements

    int as[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]); // Read n integers from input
    }

    // Sort the array to find unique elements
    qsort(as, n, sizeof(int), compare);

    // Count unique elements
    int uniqueCount = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || as[i] != as[i - 1]) {
            uniqueCount++;
        }
    }

    // Print the number of unique integers found
    printf("%d\n", uniqueCount);

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
