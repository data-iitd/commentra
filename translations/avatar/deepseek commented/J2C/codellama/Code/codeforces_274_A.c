#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n; // Step 1: Declare variables
    long k;
    long *arr;
    int count = 0;
    bool *set;

    scanf("%d", &n); // Step 2: Read input values
    scanf("%ld", &k);
    arr = (long *)malloc(n * sizeof(long));
    set = (bool *)malloc(n * sizeof(bool));

    for (int i = 0; i < n; i++) { // Step 3: Read array elements
        scanf("%ld", &arr[i]);
    }

    qsort(arr, n, sizeof(long), compare); // Step 4: Sort the array

    for (int i = 0; i < n; i++) { // Step 5: Iterate through the array
        if (arr[i] % k != 0) { // Check if the element is not divisible by k
            count++; // Increment the count
            set[i] = true; // Add the element to the set
        } else if (!set[arr[i] / k]) { // Check if the quotient is not in the set
            count++; // Increment the count
            set[i] = true; // Add the element to the set
        }
    }

    printf("%d\n", count); // Step 6: Print the result

    free(arr);
    free(set);

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(long *)a - *(long *)b);
}

