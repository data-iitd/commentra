
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a subsequence
typedef struct {
    int *arr;  // Pointer to the array of elements
    int size;  // Size of the array
} Subsequence;

// Function to perform binary search to find the position to insert a new element
int binary_search(int key, Subsequence *ans, int N) {
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
    int N;  // Number of elements
    scanf("%d", &N);
    
    Subsequence *ans = (Subsequence *)malloc(sizeof(Subsequence) * N);
    
    for (int i = 0; i < N; i++) {
        int A;  // Current element
        scanf("%d", &A);
        
        int idx = binary_search(A, ans, i);
        
        if (idx == i) {
            ans[idx].arr = (int *)malloc(sizeof(int));
            ans[idx].arr[0] = A;
            ans[idx].size = 1;
        } else {
            ans[idx].arr = (int *)realloc(ans[idx].arr, sizeof(int) * (ans[idx].size + 1));
            ans[idx].arr[ans[idx].size] = A;
            ans[idx].size++;
        }
    }
    
    int num_subsequences = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i].size > 0) {
            num_subsequences++;
        }
    }
    
    printf("%d\n", num_subsequences);
    
    for (int i = 0; i < N; i++) {
        free(ans[i].arr);
    }
    free(ans);
    
    return 0;
}

