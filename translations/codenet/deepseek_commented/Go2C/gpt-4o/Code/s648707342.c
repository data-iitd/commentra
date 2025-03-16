#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} arm;

<<<<<<< HEAD
// Comparator function for sorting arms based on their right endpoints.
=======
// Comparison function for sorting arms based on their right endpoints.
>>>>>>> 98c87cb78a (data updated)
int compare(const void *a, const void *b) {
    return ((arm *)a)->r - ((arm *)b)->r;
}

int main() {
    // Reads the number of arms.
    int n;
    scanf("%d", &n);
    
    // Creates an array to store the arms.
    arm *as = (arm *)malloc(n * sizeof(arm));
    
    // Reads each arm's range and stores the left and right endpoints.
    for (int i = 0; i < n; i++) {
        int x, l;
        scanf("%d %d", &x, &l);
        as[i].l = x - l;
        as[i].r = x + l;
    }
    
    // Sorts the arms based on their right endpoints.
    qsort(as, n, sizeof(arm), compare);
    
    // Initializes the answer and the right endpoint reference.
    int ans = 1;
    int r = as[0].r;
    
    // Iterates through the sorted arms to count non-overlapping arms.
    for (int i = 1; i < n; i++) {
        if (as[i].l >= r) {
            ans++;
            r = as[i].r;
        }
    }
    
    // Prints the count of non-overlapping arms.
    printf("%d\n", ans);
    
    // Frees the allocated memory.
    free(as);
    
    return 0;
}

// <END-OF-CODE>
