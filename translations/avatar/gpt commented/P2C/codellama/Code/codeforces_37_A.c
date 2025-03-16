#include <stdio.h>

int main()
{
    int n, i, high = 1, tower = 0, maximum = 1;

    // Read the number of elements from user input
    scanf("%d", &n);

    // Read the list of integers from user input and convert them to a list of integers
    int l[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }

    // Sort the list of integers to facilitate grouping of identical values
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (l[i] > l[j])
            {
                int temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }

    // Iterate through the sorted list starting from the second element
    for (i = 1; i < n; i++)
    {
        // Check if the current element is the same as the previous one
        if (l[i] == l[i - 1])
        {
            // If they are the same, increment the height of the current tower and decrease the tower count
            tower -= 1;
            high += 1;
        }
        else
        {
            // If they are different, check if the current tower's height is greater than the maximum found so far
            if (high > maximum)
            {
                maximum = high;
            }
            // Reset the height for the new tower
            high = 1;
        }
    }

    // After the loop, check again if the last tower's height is greater than the maximum found
    if (high > maximum)
    {
        maximum = high;
    }

    // Print the maximum height of the towers and the total number of towers
    printf("%d %d\n", maximum, tower);

    return 0;
}

