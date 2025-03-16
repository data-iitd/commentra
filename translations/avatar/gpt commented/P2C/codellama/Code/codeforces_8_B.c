#include <stdio.h>
#include <string.h>

int main()
{
    // Read the input string representing movements
    char record_of_movements[100];
    scanf("%s", record_of_movements);

    // Initialize the starting coordinates (x, y) at (0, 0)
    int x = 0, y = 0;

    // Define the movement directions: Left (L), Right (R), Up (U), Down (D)
    int d_movement[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };

    // Create a dictionary to track visited coordinates, starting with the initial position
    int d[100][2];
    d[0][0] = x;
    d[0][1] = y;

    // Initialize a flag to detect if a bug occurs
    int bug = 0;

    // Iterate through each movement in the input string
    for (int i = 0; i < strlen(record_of_movements); i++)
    {
        // Store the current position before the move
        int temp[2] = {x, y};

        // Update the coordinates based on the movement direction
        x += d_movement[record_of_movements[i] - 'A'][0];
        y += d_movement[record_of_movements[i] - 'A'][1];

        // Check if the new position has already been visited
        if (d[x][y] == 0)
        {
            // If not visited, check for potential bugs by looking at all movement directions
            for (int j = 0; j < 4; j++)
            {
                // Check if moving in any direction from the new position leads to a visited position
                if (x + d_movement[j][0] != temp[0] || y + d_movement[j][1] != temp[1])
                {
                    if (d[x + d_movement[j][0]][y + d_movement[j][1]] != 0)
                    {
                        // If a bug is detected, set the flag and break the loop
                        bug = 1;
                        break;
                    }
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
        d[x][y] = 1;
    }

    // After processing all movements, check if a bug was detected
    if (bug)
    {
        // Print 'BUG' if a bug was found
        printf("BUG\n");
    }
    else
    {
        // Print 'OK' if no bugs were found
        printf("OK\n");
    }

    return 0;
}

