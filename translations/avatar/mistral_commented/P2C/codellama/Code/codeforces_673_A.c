#include <stdio.h>

int main()
{
    int n, i, j, arr[100], diff;

    // Take the number of elements in the list as input
    scanf("%d", &n);

    // Initialize an empty list 'arr' to store the input elements
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Check if the first element of the list is greater than 15
    if (arr[0] > 15)
    {
        // If it is, print 15
        printf("15\n");
    }
    else
    {
        // Else, iterate through the list starting from the second element
        for (i = 1; i < n; i++)
        {
            // Check if the difference between the current and previous elements is greater than 15
            diff = arr[i] - arr[i - 1];
            if (diff > 15)
            {
                // If it is, print the index of the previous element and add 15 to it
                printf("%d\n", arr[i - 1] + 15);
                // Break the loop as we have found the answer
                break;
            }
        }
        // Else, if we reach here, it means that no difference was greater than 15
        if (i == n)
        {
            // Check if the last element of the list is 90 or if adding 15 to it results in 90 or more
            if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90)
            {
                // If it is, print 90
                printf("90\n");
            }
            else
            {
                // Else, print the last element plus 15
                printf("%d\n", arr[n - 1] + 15);
            }
        }
    }

    // End of code
    printf("