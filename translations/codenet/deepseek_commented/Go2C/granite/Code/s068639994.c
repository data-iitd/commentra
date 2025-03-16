
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mainFn is the main logic of the program.
void mainFn() {
    // Get the number of elements in the slice.
    int n = getInt();
    // Get the slice of integers.
    int *ls = getIntSlice(n);
    // Create a reversed version of the slice.
    int *lsRev = (int *)malloc(sizeof(int) * n);
    memcpy(lsRev, ls, sizeof(int) * n);
    // Sort the original slice in ascending order.
    qsort(ls, n, sizeof(int), compareInt);
    // Sort the reversed slice in descending order.
    qsort(lsRev, n, sizeof(int), compareIntDesc);

    // Initialize the answer variable.
    int ans = 0;
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
            int l = binarySearch(ls, n, x);
            // Find the right boundary using binary search.
            int r = n - binarySearch(lsRev, n, y);

            // Calculate the sum of valid pairs.
            int sum = r - l;
            // Adjust the sum if the current indices are within the range.
            if ((i >= l) && (i <= r)) {
                sum--;
            }
            if ((j >= l) && (j <= r)) {
                sum--;
            }
            // Ensure the sum is not negative.
            sum = max(0, sum);
            // Add the sum to the answer.
            ans += sum;
        }
    }

    // Divide the answer by 3 to get the final result.
    ans /= 3;
    // Print the final answer.
    printf("%d\n", ans);
}

// Helper functions to find the minimum and maximum of two integers.
int min(int a, int b) {
    return a < b? a : b;
}

int max(int a, int b) {
    return a > b? a : b;
}

// Binary search function to find the index of a target value in a sorted array.
int binarySearch(int *arr, int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Compare function for qsort to sort an array of integers in ascending order.
int compareInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Compare function for qsort to sort an array of integers in descending order.
int compareIntDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// getInt reads an integer from the standard input.
int getInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// getIntSlice reads a slice of integers from the standard input.
int *getIntSlice(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// getString reads a string from the standard input.
char *getString() {
    int bufSize = 200001;
    char *buf = (char *)malloc(sizeof(char) * bufSize);
    fgets(buf, bufSize, stdin);
    char *str = (char *)malloc(sizeof(char) * strlen(buf));
    strcpy(str, buf);
    return str;
}

// puts writes the arguments to the standard output.
void puts(int a) {
    printf("%d\n", a);
}

// puts writes the arguments to the standard output.
void puts(char *a) {
    printf("%s", a);
}

// puts writes the arguments to the standard output.
void puts(char *a, char *b) {
    printf("%s %s\n", a, b);
}

// puts writes the arguments to the standard output.
void puts(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// puts writes the arguments to the standard output.
void puts(char **a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");
}

// END-OF-CODE