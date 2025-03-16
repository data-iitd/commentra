#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y, i, j, k, arr[100], flag = 0;

    // Take an integer input from the user
    scanf("%d", &y);

    // Take a list of integers as input from the user
    for (i = 0; i < y; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Iterate through each index 'i' in the list 'arr'
    for (i = 0; i < y; i++)
    {
        // Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
        for (j = i + 1; j < y; j++)
        {
            // Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
            for (k = 0; k < y; k++)
            {
                // Check if the current indices 'i', 'j' and 'k' satisfy the given condition
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j])
                {
                    // If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
                    printf("%d %d %d", k + 1, j + 1, i + 1);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }

    // If no such indices are found, print -1
    if (flag == 0)
    {
        printf("-1");
    }

    return 0;
}

