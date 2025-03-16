#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Take the first line of input which are two integers 'num' and 'k'
    int num, k;
    scanf("%d %d", &num, &k);

    // Comment: Initialize 'num' and 'k' with the values from user input

    // Take the second line of input which is a list 'arr' of integers
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Comment: Initialize an empty list 'arr' to store the input integers

    // Create an empty set 'different' to store unique integers
    int different[num];
    int different_size = 0;

    // Comment: Initialize an empty set 'different' to store unique integers

    // Sort the list 'arr' in ascending order
    qsort(arr, num, sizeof(int), compare);

    // Comment: Sort the list 'arr' in ascending order for easier comparison

    // Iterate through each integer 'x' in the sorted list 'arr'
    for (int i = 0; i < num; i++)
    {
        // Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
        if (arr[i] % k != 0 || !is_in_set(arr[i] / k, different, different_size))
        {
            // If the condition is true, add 'x' to the set 'different'
            different[different_size++] = arr[i];

            // Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'
        }

        // Update the maximum length of 'different' seen so far
        int temp = max(different_size, temp);

        // Comment: After the loop, 'temp' stores the maximum length of 'different' seen during the iteration
    }

    // Print the maximum length of 'different'
    printf("%d", temp);

    // Comment: Finally, print the maximum length of 'different'

    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int is_in_set(int x, int *set, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (set[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

// END-OF-CODE
