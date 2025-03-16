#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize an empty list to store the sequence
    int *L = NULL;
    int L_size = 0;

    // Read input (not used, but could be for prompting the user)
    // scanf("%*[^\n]%*c");

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    char *k = NULL;
    while (scanf("%ms", &k) == 1)
    {
        // Extend the list 'L' by adding 'r' for 'int(k)' times
        L = realloc(L, (L_size + int(k)) * sizeof(int));
        for (int i = L_size; i < L_size + int(k); i++)
        {
            L[i] = r;
        }
        L_size += int(k);
        // Increment 'r' for the next number
        r += 1;
    }

    // Read another line of input (not used, but could be for prompting the user)
    // scanf("%*[^\n]%*c");

    // Read a line of input, split it into parts, and iterate over each part
    char *j = NULL;
    while (scanf("%ms", &j) == 1)
    {
        // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
        printf("%d\n", L[int(j) - 1]);
    }

    // Free the memory allocated for 'L'
    free(L);

    return 0;
}

