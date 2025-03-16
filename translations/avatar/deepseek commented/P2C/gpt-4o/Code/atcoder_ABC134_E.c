#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Define a maximum size for the list of lists

int binary_search(int key, int ans[][MAX_SIZE], int *sizes, int num_lists) {
    int bad = -1, good = num_lists;

    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid][sizes[mid] - 1] < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }

    return good;
}

int main() {
    int N;
    scanf("%d", &N);

    int ans[MAX_SIZE][MAX_SIZE]; // List of lists
    int sizes[MAX_SIZE] = {0}; // Array to keep track of sizes of each sublist
    int num_lists = 0; // Number of unique lists

    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, sizes, num_lists);
        
        if (idx == num_lists) {
            // If the key should be inserted at the end, create a new sublist
            ans[num_lists][0] = A;
            sizes[num_lists] = 1;
            num_lists++;
        } else {
            // Otherwise, insert the key into the appropriate sublist
            ans[idx][sizes[idx]] = A;
            sizes[idx]++;
        }
    }

    // Print the number of unique elements
    printf("%d\n", num_lists);

    return 0;
}

// <END-OF-CODE>
