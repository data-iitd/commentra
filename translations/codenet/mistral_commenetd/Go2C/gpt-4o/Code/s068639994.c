#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to read an integer from standard input
int getInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read an array of integers from standard input
int* getIntSlice(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = getInt();
    }
    return arr;
}

// Main function
int main() {
    // Get the number of elements in the input array
    int n = getInt();
    // Get the input array
    int *ls = getIntSlice(n);
    // Create a reversed copy of the input array
    int *lsRev = (int *)malloc(n * sizeof(int));
    memcpy(lsRev, ls, n * sizeof(int));
    
    // Sort the input array in ascending order
    qsort(ls, n, sizeof(int), compare);
    // Sort the reversed copy of the array in descending order
    qsort(lsRev, n, sizeof(int), compare);
    for (int i = 0; i < n / 2; i++) {
        int temp = lsRev[i];
        lsRev[i] = lsRev[n - 1 - i];
        lsRev[n - 1 - i] = temp;
    }

    // Initialize the answer variable
    long long ans = 0;
    // Iterate through all pairs of elements in the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Find the minimum and maximum elements of the current pair
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            // Calculate the difference between the maximum and minimum elements
            int x = q - p;
            int y = q + p;

            // Find the indices of the elements greater than x and less than y
            int l = 0, r = n;
            while (l < n && ls[l] <= x) l++;
            while (r > 0 && lsRev[r - 1] >= y) r--;

            // Calculate the sum of the difference between the indices
            long long sum = r - l;
            // Check if the current pair lies within the range [l, r]
            if (i >= l && i < r) sum--;
            if (j >= l && j < r) sum--;
            // Ensure that the sum is not negative
            sum = max(0, sum);
            // Add the sum to the answer variable
            ans += sum;
        }
    }
    // Divide the answer by 3 and print it
    ans /= 3;
    printf("%lld\n", ans);

    // Free allocated memory
    free(ls);
    free(lsRev);
    
    return 0;
}

// <END-OF-CODE>
