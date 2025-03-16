#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[1000]; // Step 1: The program starts by taking a string input from the user.
    scanf("%s", s);

    int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
    int *counter;

    if (strcmp(s, "") == 0) // Step 3: It checks if the input string is empty and returns immediately if it is.
    {
        return 0;
    }
    counter = (int *)malloc(sizeof(int)); // Step 4: It splits the input string into individual characters.
    char *li = strtok(s, "");

    while (li != NULL) // Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.
    {
        if (strcmp(li, "A") == 0 || strcmp(li, "C") == 0 || strcmp(li, "G") == 0 || strcmp(li, "T") == 0)
        {
            count++;
        }
        else
        {
            counter = (int *)realloc(counter, sizeof(int) * (count + 1));
            counter[count] = count;
            count = 0;
        }
        li = strtok(NULL, "");
    }

    counter = (int *)realloc(counter, sizeof(int) * (count + 1)); // Step 6: It appends the final count to the counter array and sorts the array.
    counter[count] = count;
    qsort(counter, count + 1, sizeof(int), compare);
    printf("%d\n", counter[count]); // Step 7: Finally, it prints the maximum value in the sorted counter array.
    free(counter);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

