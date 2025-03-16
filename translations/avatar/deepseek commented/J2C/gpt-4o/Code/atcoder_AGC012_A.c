#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Step 1: Read the input value `n` which represents the number of elements to process.
    int n;
    scanf("%d", &n);
    
    // Step 2: Read the array of size `3 * n` from the standard input.
    int *array = (int *)malloc(3 * n * sizeof(int));
    for (int i = 0; i < 3 * n; i++) {
        scanf("%d", &array[i]);
    }
    
    // Step 3: Sort the array in ascending order.
    qsort(array, 3 * n, sizeof(int), compare);
    
    // Step 4: Initialize a variable `head` to point to the second last element of the array.
    int head = 3 * n - 2;
    
    // Step 5: Initialize a variable `res` to store the result.
    long long res = 0;
    
    // Step 6: Iterate `n` times, in each iteration:
    // - Add the value at the `head` position to `res`.
    // - Decrement `head` by 2.
    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }
    
    // Step 7: Print the result `res`.
    printf("%lld\n", res);
    
    // Free the allocated memory
    free(array);
    
    return 0;
}

// <END-OF-CODE>
