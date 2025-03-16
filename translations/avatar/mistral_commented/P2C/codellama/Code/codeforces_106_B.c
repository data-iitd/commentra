#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the number of items in the input array
    int n;
    scanf("%d", &n);

    // Initialize an empty list to store the input data
    int input_array[n][4];

    // Read n items from the standard input and append them to the input_array
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &input_array[i][0], &input_array[i][1], &input_array[i][2], &input_array[i][3]);
    }

    // Initialize an empty list to store the outdated items
    int outdated[n];

    // Check for outdated items in the input array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Check if the current item is older and smaller than the next one
            if (input_array[i][0] < input_array[j][0] && input_array[i][1] < input_array[j][1] && input_array[i][2] < input_array[j][2])
            {
                // Append the current item to the outdated list
                outdated[i] = input_array[i][3];
            }
        }
    }

    // Initialize minimum_cost and input_number to large initial values
    int minimum_cost = 100000;
    int input_number = 0;

    // Find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++)
    {
        // Check if the current item is not outdated and has a smaller cost than minimum_cost
        if (outdated[i] != 1 && input_array[i][3] < minimum_cost)
        {
            // Update minimum_cost and input_number
            minimum_cost = input_array[i][3];
            input_number = i + 1;
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    printf("%d", input_number);

    return 0;
}

