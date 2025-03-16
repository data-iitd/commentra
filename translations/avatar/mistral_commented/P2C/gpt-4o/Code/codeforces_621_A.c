#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    // Take an integer 'n' as input
    int n;
    scanf("%d", &n);

    // Create a list 'lst' of 'n' integers taken as input
    int *lst = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }

    // Sort the list 'lst' in descending order
    qsort(lst, n, sizeof(int), compare);

    // Initialize odd_digits counter 'od' to 0
    int od = 0;

    // Iterate through each integer 'i' in the list 'lst'
    for (int i = 0; i < n; i++) {
        // If the integer 'i' has an odd number of bits (1 in binary representation), increment 'od' counter
        if (lst[i] & 1) {
            od++;
        }
    }

    // Initialize sum and ok variables
    int sum = 0;
    int ok = 0;

    // Iterate through each index 'i' in the range of 'n'
    for (int i = 0; i < n; i++) {
        // If the integer at index 'i' in the list 'lst' is even, add it to the sum 'sum'
        if (lst[i] % 2 == 0) {
            sum += lst[i];
        } 
        // If the integer at index 'i' in the list 'lst' is odd and either 'ok' is True or 'od' is greater than 1, add it to the sum 'sum' and toggle 'ok'
        else {
            if (ok || od > 1) {
                sum += lst[i];
                od--;
                ok = !ok;
            }
        }
    }

    // Print the final sum
    printf("%d\n", sum);

    // Free allocated memory
    free(lst);

    return 0;
}

// <END-OF-CODE>
