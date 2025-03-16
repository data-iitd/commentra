
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *arr;
    int n;
    long total;
    long *bit;
} Task;

Task *createTask(int n) {
    Task *tsk = (Task *) malloc(sizeof(Task));
    tsk->arr = (int *) malloc(sizeof(int) * n);
    tsk->bit = (long *) malloc(sizeof(long) * (2 * n + 2));
    tsk->n = n;
    tsk->total = (long) n * (n + 1) / 2;
    return tsk;
}

void destroyTask(Task *tsk) {
    free(tsk->arr);
    free(tsk->bit);
    free(tsk);
}

void solveTask(Task *tsk) {
    int n = tsk->n;
    int *arr = tsk->arr;
    long *bit = tsk->bit;
    
    // Populate the array with input integers
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    // Create a sorted copy of the input array
    int *sorted = (int *) malloc(sizeof(int) * n);
    memcpy(sorted, arr, sizeof(int) * n);
    qsort(sorted, n, sizeof(int), cmpfunc);
    
    // Perform binary search to find the median-like value
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = sorted[mid];
        
        // Initialize counters for the current state
        int cur = 0;
        long cnt = 0;
        
        // Initialize the BIT with base values
        memset(bit, 0, sizeof(long) * (2 * n + 2));
        for (int x = n + 1; x < 2 * n + 2; x += x & -x)
            bit[x]++;
        
        // Count the number of elements less than or equal to the target
        for (int i = 0; i < n; i++) {
            cur += arr[i] <= target? 1 : -1;
            
            // Update the BIT with the current count
            for (int x = cur + n + 1; x < 2 * n + 2; x += x & -x)
                bit[x]++;
            
            // Count the number of valid pairs using the BIT
            for (int x = cur + n; x > 0; x -= x & -x)
                cnt += bit[x];
        }
        
        // Adjust the search range based on the count of pairs
        if (cnt >= tsk->total / 2 + 1)
            r = mid; // Move left if count is sufficient
        else
            l = mid + 1; // Move right if count is insufficient
    }
    
    // Print the median-like value found
    printf("%d\n", sorted[l]);
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    int n;
    scanf("%d", &n);
    Task *tsk = createTask(n);
    solveTask(tsk);
    destroyTask(tsk);
    return 0;
}

