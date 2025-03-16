#include <stdio.h>
#include <stdlib.h>

int binary_search(int key, int *arr, int low, int high) {
    // Initialize bad and good indices for binary search
    int bad = -1, good = high;
    
    // Perform binary search to find the correct position
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (arr[mid] < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }
    
    // Return the index where the key should be inserted
    return good;
}

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);
    
    // Initialize the list of lists
    int **ans = (int **)malloc(N * sizeof(int *));
    
    // Read each element and insert it into the appropriate position
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, 0, i);
        if (idx == i) {
            // If the key should be inserted at the end, append a new sublist
            ans[i] = (int *)malloc(sizeof(int));
            ans[i][0] = A;
        } else {
            // Otherwise, insert the key into the appropriate sublist
            int *temp = (int *)malloc((i - idx) * sizeof(int));
            for (int j = 0; j < i - idx; j++) {
                temp[j] = ans[idx + j][0];
            }
            ans[idx] = (int *)malloc((i - idx + 1) * sizeof(int));
            for (int j = 0; j < i - idx; j++) {
                ans[idx][j] = temp[j];
            }
            ans[idx][i - idx] = A;
            free(temp);
        }
    }
    
    // Print the number of unique elements
    printf("%d\n", N);
    
    // Free the memory
    for (int i = 0; i < N; i++) {
        free(ans[i]);
    }
    free(ans);
    
    return 0;
}

