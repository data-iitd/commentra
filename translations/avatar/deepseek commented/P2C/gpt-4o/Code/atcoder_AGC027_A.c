#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, x;
    
    // Read n and x from input
    scanf("%d %d", &n, &x);
    
    int *a = (int *)malloc(n * sizeof(int));
    
    // Read the list a from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the array a in ascending order
    qsort(a, n, sizeof(int), compare);
    
    int ans = 0;
    
    // Check if the smallest element in the sorted list a is greater than x
    if (a[0] > x) {
        printf("0\n");
        free(a);
        return 0;
    }
    
    // Iterate through each element in the sorted list a
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            x = 0;
            break;
        }
        x -= a[i];
        ans++;
    }
    
    // If x is not 0 after the loop, decrement ans by 1
    if (x != 0) {
        ans--;
    }
    
    // Print the value of ans
    printf("%d\n", ans);
    
    free(a);
    return 0;
}

// <END-OF-CODE>
