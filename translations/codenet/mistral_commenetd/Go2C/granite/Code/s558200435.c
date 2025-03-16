

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize the variable 'n' to read the number of elements in the array 'a'
    int n;
    scanf("%d", &n);

    // Create an array 'a' of length 'n' to store the input elements
    int a[n];

    // Read 'n' elements from the standard input and store them in array 'a'
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize an empty array 'b' to store the unique elements
    int b[n];
    int b_len = 0;

    // Iterate through each element 'v' in array 'a'
    for (int i = 0; i < n; i++) {
        int v = a[i];

        // Use 'binary_search' function to find the index 'x' where 'v' should be inserted in array 'b'
        int x = binary_search(b, b_len, v);

        // If 'x' is equal to the length of array 'b', it means 'v' is not present in the array, so append it
        if (x == b_len) {
            b[b_len] = v;
            b_len++;
        } else {
            // Otherwise, replace the element at index 'x' in array 'b' with 'v'
            b[x] = v;
        }
    }

    // Print the length of array 'b' as the output
    printf("%d\n", b_len);

    // End of the code
    return 0;
}

int binary_search(int arr[], int len, int target) {
    int left = 0;
    int right = len - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

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

