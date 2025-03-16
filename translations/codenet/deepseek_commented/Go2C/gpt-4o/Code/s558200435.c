#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n; // 1. Reading the input number of elements (n)
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int)); // 2. Reading the elements into a dynamic array (a)
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *b = (int *)malloc(n * sizeof(int)); // 3. Creating a dynamic array (b) to store the longest increasing subsequence
    int b_len = 0; // Length of the longest increasing subsequence

    for (int i = 0; i < n; i++) { // 4. Finding the longest increasing subsequence
        int v = a[i];
        int *pos = (int *)bsearch(&v, b, b_len, sizeof(int), compare);
        if (pos == NULL) {
            b[b_len++] = v; // Append to b if v is greater than all elements in b
        } else {
            *pos = v; // Replace the found position with v
        }
    }

    printf("%d\n", b_len); // 5. Outputting the length of the longest increasing subsequence

<<<<<<< HEAD
    free(a); // Free the allocated memory for a
    free(b); // Free the allocated memory for b
=======
    free(a); // Free allocated memory
    free(b); // Free allocated memory
>>>>>>> 98c87cb78a (data updated)
    return 0;
}
