#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Sort the array A
    qsort(A, n, sizeof(int), compare);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x >= A[i]) {
            ans++;
            x -= A[i];
        } else {
            break;
        }
    }
    if (ans == n && x > 0) {
        ans--;
    }
    
    printf("%d\n", ans);
    
    free(A);
    return 0;
}

// <END-OF-CODE>
