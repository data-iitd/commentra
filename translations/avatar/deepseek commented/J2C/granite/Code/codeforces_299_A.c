

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Read the input value n, which represents the number of elements in the array.
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    // Step 2: Create an array 'a' of size n and read n elements from the input.
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Step 3: Sort the array 'a'.
    qsort(a, n, sizeof(int), cmpfunc);

    // Step 4: Find the minimum element in the sorted array 'a'.
    int min = a[0];

    // Step 5: Check if all elements in the array are divisible by the minimum element. If not, print -1 and exit.
    for (int i = 0; i < n; i++) {
        if (a[i] % min!= 0) {
            printf("-1\n");
            return 0;
        }
    }

    // Step 6: If all elements are divisible, print the minimum element.
    printf("%d\n", min);

    // Free the memory allocated for the array 'a'.
    free(a);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

