
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a sublist
typedef struct {
    int *arr;
    int size;
} Sublist;

// Function to perform binary search to find the correct position for insertion
int binary_search(int key, Sublist *ans, int N) {
    int bad = -1, good = N;
    while (good - bad > 1) {
        int mid = (bad + good) / 2;
        if (ans[mid].arr[ans[mid].size - 1] < key) {
            good = mid;
        } else {
            bad = mid;
        }
    }
    return good;
}

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Initialize the list of lists
    Sublist *ans = (Sublist *)malloc(sizeof(Sublist) * N);

    // Read each element and insert it into the appropriate position
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        int idx = binary_search(A, ans, N);
        if (idx == N) {
            // If the key should be inserted at the end, append a new sublist
            ans[idx].arr = (int *)malloc(sizeof(int));
            ans[idx].arr[0] = A;
            ans[idx].size = 1;
        } else {
            // Otherwise, insert the key into the appropriate sublist
            int *new_arr = (int *)malloc(sizeof(int) * (ans[idx].size + 1));
            for (int j = 0; j < ans[idx].size; j++) {
                new_arr[j] = ans[idx].arr[j];
            }
            new_arr[ans[idx].size] = A;
            free(ans[idx].arr);
            ans[idx].arr = new_arr;
            ans[idx].size++;
        }
    }

    // Print the number of unique elements
    int unique_count = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i].size > 0) {
            unique_count++;
        }
    }
    printf("%d\n", unique_count);

    // Free the memory allocated for the list of lists
    for (int i = 0; i < N; i++) {
        free(ans[i].arr);
    }
    free(ans);

    return 0;
}
