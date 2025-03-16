#include <stdio.h>
#include <stdlib.h>

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int* nextInts(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt();
    }
    return arr;
}

int main() {
    // Read the number of integers
    int n = nextInt();
    // Read the integers into an array
    int* a = nextInts(n);

    // Initialize the answer counter
    int ans = 0;

    // Iterate through the array of integers
    for (int i = 0; i < n; i++) {
        // Set the left and right pointers for the current segment
        int l = i, r = i + 1;

        // Expand the right pointer while the conditions are met
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }

        // Increment the answer for each segment found
        ans++;
        // Move the left pointer to the end of the current segment
        i = r;
    }

    // Output the final count of segments
    printf("%d\n", ans);

    // Free the allocated memory
    free(a);

    return 0;
}

// <END-OF-CODE>
