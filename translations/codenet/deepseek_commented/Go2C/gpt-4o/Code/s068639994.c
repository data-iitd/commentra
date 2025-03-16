#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
// Function to read an integer from standard input.
int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a slice of integers from standard input.
int* getIntSlice(int n) {
    int* is = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        is[i] = getInt();
    }
    return is;
}

// Function to find the minimum of two integers.
=======
// Function to compare two integers for qsort
int compareAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to find the minimum of two integers
>>>>>>> 98c87cb78a (data updated)
int min(int a, int b) {
    return (a < b) ? a : b;
}

<<<<<<< HEAD
// Function to find the maximum of two integers.
=======
// Function to find the maximum of two integers
>>>>>>> 98c87cb78a (data updated)
int max(int a, int b) {
    return (a > b) ? a : b;
}

<<<<<<< HEAD
// Comparison function for qsort to sort in ascending order.
int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Comparison function for qsort to sort in descending order.
int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

// Function to perform binary search for the left boundary.
int binarySearchLeft(int* arr, int size, int x) {
=======
// Function to perform binary search for the left boundary
int binarySearchLeft(int *arr, int size, int x) {
>>>>>>> 98c87cb78a (data updated)
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

<<<<<<< HEAD
// Function to perform binary search for the right boundary.
int binarySearchRight(int* arr, int size, int y) {
=======
// Function to perform binary search for the right boundary
int binarySearchRight(int *arr, int size, int y) {
>>>>>>> 98c87cb78a (data updated)
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < y) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

<<<<<<< HEAD
// Main function containing the logic of the program.
int main() {
    // Get the number of elements in the slice.
    int n = getInt();
    // Get the slice of integers.
    int* ls = getIntSlice(n);
    // Create a reversed version of the slice.
    int* lsRev = (int*)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));
    
    // Sort the original slice in ascending order.
    qsort(ls, n, sizeof(int), compareAsc);
    // Sort the reversed slice in descending order.
    qsort(lsRev, n, sizeof(int), compareDesc);

    // Initialize the answer variable.
    long long ans = 0;
    // Loop through the slice to calculate the answer.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate p and q based on the current elements.
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate x and y based on p and q.
            int x = q - p;
            int y = q + p;

            // Find the left boundary using binary search.
            int l = binarySearchLeft(ls, n, x);
            // Find the right boundary using binary search.
            int r = n - binarySearchRight(lsRev, n, y);

            // Calculate the sum of valid pairs.
            int sum = r - l;
            // Adjust the sum if the current indices are within the range.
            if (i >= l && i < r) {
                sum--;
            }
            if (j >= l && j < r) {
                sum--;
            }
            // Ensure the sum is not negative.
            sum = max(0, sum);
            // Add the sum to the answer.
=======
int main() {
    int n;
    scanf("%d", &n);
    
    int *ls = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ls[i]);
    }

    // Create a reversed version of the array
    int *lsRev = (int *)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));

    // Sort the original array in ascending order
    qsort(ls, n, sizeof(int), compareAsc);
    // Sort the reversed array in descending order
    qsort(lsRev, n, sizeof(int), compareDesc);

    // Initialize the answer variable
    long long ans = 0;

    // Loop through the array to calculate the answer
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate p and q based on the current elements
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate x and y based on p and q
            int x = q - p;
            int y = q + p;

            // Find the left boundary using binary search
            int l = binarySearchLeft(ls, n, x);
            // Find the right boundary using binary search
            int r = n - binarySearchRight(lsRev, n, y);

            // Calculate the sum of valid pairs
            int sum = r - l;
            // Adjust the sum if the current indices are within the range
            if (i >= l && i < r) sum--;
            if (j >= l && j < r) sum--;
            // Ensure the sum is not negative
            sum = max(0, sum);
            // Add the sum to the answer
>>>>>>> 98c87cb78a (data updated)
            ans += sum;
        }
    }

<<<<<<< HEAD
    // Divide the answer by 3 to get the final result.
    ans /= 3;
    // Print the final answer.
    printf("%lld\n", ans);

    // Free allocated memory.
    free(ls);
    free(lsRev);
    
=======
    // Divide the answer by 3 to get the final result
    ans /= 3;
    // Print the final answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(ls);
    free(lsRev);

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
