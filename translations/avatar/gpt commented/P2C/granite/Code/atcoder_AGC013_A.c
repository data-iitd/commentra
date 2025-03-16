
#include <stdio.h>

int main() {
    int N, A[100000], i, ans;

    // Read the number of elements
    scanf("%d", &N);

    // Read the list of integers
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Remove consecutive duplicates from the list
    i = 1;
    while (i < N - 1) {
        if (A[i - 1] == A[i] || A[i] == A[i + 1]) {
            for (int j = i; j < N - 1; j++) {
                A[j] = A[j + 1];
            }
            N--;
        } else {
            i++;
        }
    }

    // Initialize the index and answer counter
    i = 1;
    ans = 0;

    // Loop through the list to count the number of peaks and valleys
    while (i < N - 1) {
        // Check if the current element is a peak or a valley
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            ans++;  // Increment the answer for each peak/valley found
            i++;    // Skip the next element to avoid double counting
        } else if (A[i - 1] > A[i] && A[i] < A[i + 1]) {
            ans++;  // Increment the answer for each peak/valley found
            i++;    // Skip the next element to avoid double counting
        }
        i++;  // Move to the next element
    }

    // Print the total count of peaks and valleys plus one
    printf("%d\n", ans + 1);

    return 0;
}
