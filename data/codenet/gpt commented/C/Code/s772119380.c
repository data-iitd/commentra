#include <stdio.h>

int main()
{
    // Declare an array to hold up to 1000 integers and variables for size and counters
    int a[1000], n, i, j, d = 0;

    // Read the number of elements to be sorted
    scanf("%d", &n);

    // Read the elements into the array
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Perform a bubble sort on the array
    for (i = 0; i < n; i++)
    {   
        // Inner loop for comparing adjacent elements
        for (j = n - 1; j >= i + 1; j--)
        {
            // If the current element is less than the previous one, swap them
            if (a[j] < a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                d++; // Increment the swap counter
            }
        }
    }

    // Print the sorted array
    printf("%d", a[0]); // Print the first element
    for (i = 1; i < n; i++)
    {
        printf(" %d", a[i]); // Print the remaining elements
    }
    
    // Print the total number of swaps made during sorting
    printf("\n%d\n", d);
    
    return 0; // Return success
}
