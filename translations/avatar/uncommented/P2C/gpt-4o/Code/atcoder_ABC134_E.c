#include <stdio.h>
#include <stdlib.h>

int binary_search(int key, int **ans, int len) {
    int bad = -1, good = len;
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid][len - 1] < key) {
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
    
    int **ans = malloc(N * sizeof(int *));
    int *sizes = malloc(N * sizeof(int)); // To keep track of sizes of each sub-array
    int count = 0; // To keep track of the number of sub-arrays

    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, count);
        
        if (idx == count) {
            ans[count] = malloc(sizeof(int)); // Allocate space for new sub-array
            ans[count][0] = A; // Initialize the first element
            sizes[count] = 1; // Set size of the new sub-array
            count++;
        } else {
            ans[idx] = realloc(ans[idx], (sizes[idx] + 1) * sizeof(int)); // Resize the existing sub-array
            ans[idx][sizes[idx]] = A; // Append the new element
            sizes[idx]++; // Increment the size of the sub-array
        }
    }

    printf("%d\n", count);

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(ans[i]);
    }
    free(ans);
    free(sizes);

    return 0;
}

// <END-OF-CODE>
