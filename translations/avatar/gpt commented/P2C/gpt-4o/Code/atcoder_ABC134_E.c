#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000  // Define a maximum size for the subsequences

int ans[MAX_N][MAX_N];  // Array to hold the subsequences
int lengths[MAX_N];     // Array to hold the lengths of each subsequence
int num_subsequences = 0; // Number of subsequences

int binary_search(int key) {
    int bad = -1, good = num_subsequences;

    while (good - bad > 1) {
        int mid = (bad + good) / 2;  // Calculate the middle index
        // If the last element of the mid list is less than the key, move the good boundary
        if (ans[mid][lengths[mid] - 1] < key) {
            good = mid;
        } else {
            // Otherwise, move the bad boundary
            bad = mid;
        }
    }
    // Return the index where the key should be inserted
    return good;
}

int main() {
    int N;
    scanf("%d", &N);  // Read the number of elements

    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);  // Read the current element
        int idx = binary_search(A);  // Find the position to insert the element

        // If the index is equal to the number of subsequences, it means A is greater than all elements
        if (idx == num_subsequences) {
            ans[num_subsequences][0] = A;  // Start a new subsequence with A
            lengths[num_subsequences] = 1; // Set the length of the new subsequence
            num_subsequences++;
        } else {
            // Otherwise, append A to the existing subsequence at index idx
            ans[idx][lengths[idx]] = A;
            lengths[idx]++;
        }
    }

    // Print the number of subsequences formed
    printf("%d\n", num_subsequences);

    return 0;
}

// <END-OF-CODE>
