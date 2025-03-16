
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Set up input and output streams
    FILE *inputStreamReader = stdin;
    FILE *bufferedReader = stdin;
    FILE *writer = stdout;

    // Read the input string from the user
    char str[100];
    fgets(str, 100, bufferedReader);

    // Create a HashMap to count the frequency of each character in the input string
    int map[100];
    int oddCount = 0;

    // Initialize a counter for characters with odd frequencies
    for (int i = 0; i < 100; i++)
    {
        map[i] = 0;
    }

    // Iterate through the input string to populate the frequency map
    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];
        if (map[ch] != 0)
        {
            map[ch]++;
        }
        else
        {
            map[ch] = 1;
        }
    }

    // Iterate through the map to count characters with odd frequencies
    for (int i = 0; i < 100; i++)
    {
        if (map[i] % 2 != 0)
        {
            oddCount++;
        }
    }

    // Determine the winner based on the count of characters with odd frequencies
    if (oddCount <= 1 || oddCount % 2 != 0)
    {
        fprintf(writer, "First\n");
    }
    else
    {
        fprintf(writer, "Second\n");
    }

    // Flush the output to ensure the result is printed immediately
    fflush(writer);

    return 0;
}

