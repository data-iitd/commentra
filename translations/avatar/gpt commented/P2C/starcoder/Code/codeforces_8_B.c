#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read the input string representing movements
    char *record_of_movements = (char *)malloc(1000000);
    scanf("%s", record_of_movements);

    // Initialize the starting coordinates (x, y) at (0, 0)
    int x = 0, y = 0;

    // Define the movement directions: Left (L), Right (R), Up (U), Down (D)
    char d_movement[4][2] = {'L', 'R', 'U', 'D'};

    // Create a dictionary to track visited coordinates, starting with the initial position
    int d[1000000][2];
    d[0][0] = x;
    d[0][1] = y;

    // Initialize a flag to detect if a bug occurs
    int bug = 0;

    // Iterate through each movement in the input string
    for (int i = 0; i < strlen(record_of_movements); i++)
    {
        // Store the current position before the move
        int temp_x = x;
        int temp_y = y;

        // Update the coordinates based on the movement direction
        if (record_of_movements[i] == d_movement[0][0])
        {
            x -= 1;
        }
        else if (record_of_movements[i] == d_movement[1][0])
        {
            x += 1;
        }
        else if (record_of_movements[i] == d_movement[2][0])
        {
            y += 1;
        }
        else if (record_of_movements[i] == d_movement[3][0])
        {
            y -= 1;
        }

        // Check if the new position has already been visited
        int found = 0;
        for (int j = 0; j < i; j++)
        {
            if (d[j][0] == x && d[j][1] == y)
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            // If not visited, check for potential bugs by looking at all movement directions
            for (int j = 0; j < 4; j++)
            {
                // Check if moving in any direction from the new position leads to a visited position
                if (d[i][0] + d_movement[j][0]!= temp_x && d[i][1] + d_movement[j][1]!= temp_y &&
                    d[i][0] + d_movement[j][0] == d[i][0] && d[i][1] + d_movement[j][1] == d[i][1])
                {
                    // If a bug is detected, set the flag and break the loop
                    bug = 1;
                    break;
                }
            }
        }
        else
        {
            // If the new position was already visited, set the bug flag
            bug = 1;
        }

        // If a bug has been detected, exit the loop
        if (bug)
        {
            break;
        }

        // Mark the new position as visited
        d[i + 1][0] = x;
        d[i + 1][1] = y;
    }

    // After processing all movements, check if a bug was detected
    if (bug)
    {
        // Print 'BUG' if a bug was found
        printf("BUG");
    }
    else
    {
        // Print 'OK' if no bugs were found
        printf("OK");
    }

    // Free the memory allocated for the input string
    free(record_of_movements);

    return 0;
}

