#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize an empty list to store the sequence
    int *L = NULL;

    // Read input (not used, but could be for prompting the user)
    getchar();

    // Initialize a variable 'r' to keep track of the current number to be added to the list
    int r = 1;

    // Read a line of input, split it into parts, and iterate over each part
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, stdin);
    for (char *k = strtok(line, " "); k!= NULL; k = strtok(NULL, " "))
    {
        // Extend the list 'L' by adding 'r' for 'int(k)' times
        L = realloc(L, sizeof(int) * (r + 1));
        for (int i = 0; i < atoi(k); i++)
        {
            L[r] = r;
            r++;
        }
    }

    // Read another line of input (not used, but could be for prompting the user)
    getchar();

    // Read a line of input, split it into parts, and iterate over each part
    read = getline(&line, &len, stdin);
    for (char *j = strtok(line, " "); j!= NULL; j = strtok(NULL, " "))
    {
        // Print the element from list 'L' at the index specified by 'j' (adjusted for 0-based index)
        printf("%d\n", L[atoi(j) - 1]);
    }

    // Free the memory allocated for the list
    free(L);

    return 0;
}
