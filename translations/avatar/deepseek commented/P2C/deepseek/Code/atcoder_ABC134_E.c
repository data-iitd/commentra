#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binary_search(int key, int **ans, int size) {
    int bad = -1, good = size;
    
    // Perform binary search to find the correct position
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid][0] < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }
    
    // Return the index where the key should be inserted
    return good;
}

int main() {
    int N;
    
    // Read the number of elements
    scanf("%d", &N);
    
    // Initialize the list of lists
    int **ans = (int **)malloc(N * sizeof(int *));
    int size = 0;
    
    // Read each element and insert it into the appropriate position
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, size);
        if (idx == size) {
            // If the key should be inserted at the end, allocate a new sublist
            ans[size] = (int *)malloc(1 * sizeof(int));
            ans[size][0] = A;
            size++;
        } else {
            // Otherwise, insert the key into the appropriate sublist
            int *new_sublist = (int *)malloc((ans[idx][0] + 1) * sizeof(int));
            for (int j = 0; j < ans[idx][0]; j++) {
                new_sublist[j] = ans[idx][j];
            }
            new_sublist[ans[idx][0]] = A;
            free(ans[idx]);
            ans[idx] = new_sublist;
            ans[idx][0]++;
        }
    }
    
    // Print the number of unique elements
    printf("%d\n", size);
    
    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(ans[i]);
    }
    free(ans);
    
    return 0;
}
