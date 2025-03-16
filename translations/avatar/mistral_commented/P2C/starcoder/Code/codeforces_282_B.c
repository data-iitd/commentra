#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstline, A, G, total = 0;
    char *memory;
    char *memory_state;

    // Take the first line as an input
    scanf("%d", &firstline);

    // Initialize memory list
    memory = (char *)malloc(firstline * sizeof(char));
    memory_state = (char *)malloc(firstline * sizeof(char));

    // Loop through the given number of lines
    for (int x = 0; x < firstline; x++)
    {
        // Take two integers as input, A and G
        scanf("%d %d", &A, &G);

        // Check if adding A to the total memory usage is within the limit
        if (total + A <= 500)
        {
            // If yes, add A to the total and append 'A' to the memory list
            total += A;
            memory[x] = 'A';
        }
        else
        {
            // If no, subtract G from the total and append 'G' to the memory list
            total -= G;
            memory[x] = 'G';
        }
    }

    // Print the final memory state
    for (int x = 0; x < firstline; x++)
    {
        printf("%c", memory[x]);
    }

    // Free the memory
    free(memory);
    free(memory_state);

    return 0;
}

