#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binary_search(int key, int **ans, int size) {
    int bad = -1, good = size;
    
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid][0] < key) {
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
    
    // Initialize an empty list to hold the subsequences
    int *ans[N];
    int ans_size = 0;
    
    // Iterate over the range of N to read each element
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, ans_size);  // Find the position to insert the element
        
        // If the index is equal to the length of ans, it means A is greater than all elements
        if (idx == ans_size) {
            ans[ans_size] = (int *)malloc(1 * sizeof(int));  // Allocate memory for the new subsequence
            ans[ans_size][0] = A;  // Assign the value to the new subsequence
            ans_size++;  // Increment the size of ans
        } else {
            // Otherwise, reallocate memory for the existing subsequence at index idx
            int *new_subseq = (int *)realloc(ans[idx], (ans[idx][0] + 1) * sizeof(int));
            if (new_subseq != NULL) {
                ans[idx] = new_subseq;
                ans[idx][ans[idx][0]] = A;  // Append A to the existing subsequence
                ans[idx][0]++;  // Increment the size of the subsequence
            }
        }
    }
    
    // Print the number of subsequences formed
    printf("%d\n", ans_size);
    
    // Free allocated memory
    for (int i = 0; i < ans_size; i++) {
        free(ans[i]);
    }
    
    return 0;
}
