
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a scanner object to read input from the console
    int N;
    scanf("%d", &N);

    // Initialize a list to store the integers
    int *L = (int *)malloc(N * sizeof(int));

    // Read N integers from input and add them to the list
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    // Sort the list of integers in ascending order
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (L[i] > L[j]) {
                int temp = L[i];
                L[i] = L[j];
                L[j] = temp;
            }
        }
    }

    // Initialize a counter to keep track of valid pairs
    int count = 0;

    // Iterate through each pair of integers in the sorted list
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Get the current pair of integers
            int a = L[i];
            int b = L[j];

            // Find the number of integers that can form a valid triplet with a and b
            int res = find(L, j + 1, a + b);

            // Increment the count by the number of valid triplets found
            count = count + res;
        }
    }

    // Output the total count of valid triplets
    printf("%d\n", count);

    // Free the memory allocated for the list of integers
    free(L);

    return 0;
}

// Method to find the count of integers in the list that can form a valid triplet
int find(int *li, int from, int target) {
    int low = from;
    int upp = N - 1;

    // Calculate the mid index based on the current low and upper bounds
    int mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;

    // Base cases for the search
    if (upp - low < 0) {
        return 0;
    } else if (li[from] >= target) {
        return 0;
    } else if (li[upp] < target) {
        return upp - low + 1;
    }

    // Perform binary search to find the count of valid integers
    while (upp - low > 1) {
        if (li[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
        // Update mid index after adjusting low and upp
        mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;
    }

    // Return the count of valid integers found
    return low - from + 1;
}

