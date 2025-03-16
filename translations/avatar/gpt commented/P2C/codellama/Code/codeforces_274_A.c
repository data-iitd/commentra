#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read two integers from input: num (number of elements) and k (the divisor)
    int num, k;
    scanf("%d %d", &num, &k);

    // Read the array of integers from input
    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Initialize a set to keep track of unique elements that meet the criteria
    int *different = (int *)malloc(num * sizeof(int));
    int temp = 0;

    // Sort the array to process elements in ascending order
    qsort(arr, num, sizeof(int), compare);

    // Iterate through each element in the sorted array
    for (int i = 0; i < num; i++)
    {
        // Check if the element is not divisible by k or if its quotient is not already in the 'different' set
        if (arr[i] % k != 0 || !isInSet(different, temp, arr[i] / k))
        {
            // Add the element to the 'different' set since it meets the criteria
            different[temp++] = arr[i];
        }
    }

    // Print the maximum size of the 'different' set found
    printf("%d\n", temp);

    // Free allocated memory
    free(arr);
    free(different);

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int isInSet(int *set, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (set[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

