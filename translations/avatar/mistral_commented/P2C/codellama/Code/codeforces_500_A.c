# Including the header files
#include <stdio.h>
#include <stdlib.h>

// Main function starts here
int main()
{
    // Declaring and initializing the variables
    int n, t, current_cell = 0;
    scanf("%d %d", &n, &t);
    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    // Main logic of the program starts here
    while (current_cell <= t)
    {
        // Incrementing the current cell position by the jump from the previous cell
        current_cell += s[current_cell - 1];

        // Checking if the current cell position is equal to the target position
        if (current_cell == t)
        {
            // If yes, then print "YES" and exit the program
            printf("YES\n");
            return 0;
        }

        // If not, then continue to the next iteration
        else
        {
            continue;
        }
    }

    // If the loop terminates without finding the target position, then print "NO"
    printf("NO\n");

    // End of the program
    return 0;
}

