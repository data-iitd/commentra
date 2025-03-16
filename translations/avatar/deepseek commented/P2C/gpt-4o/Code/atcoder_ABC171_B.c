#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    
    // This line takes two integers, n and k, as input from the user.
    scanf("%d %d", &n, &k);
    
    int *arr = (int *)malloc(n * sizeof(int));
    
    // This line takes n integers as input from the user.
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array
    qsort(arr, n, sizeof(int), compare);
    
    // This line prints the sum of the first k smallest numbers.
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    
    printf("%d\n", sum);
    
    // Free the allocated memory
    free(arr);
    
    return 0;
}

// <END-OF-CODE>
