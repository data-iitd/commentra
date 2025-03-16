
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int Sheep = 0;
    int Wolve = 0;

    // Continuously read input lines from the user until an exception occurs
    while ((read = getline(&line, &len, stdin)) != -1) {
        // Get the first line of input and split it into an array of strings
        char *numlist[2];
        numlist[0] = strtok(line, " ");
        numlist[1] = strtok(NULL, " ");

        // Parse the first element to get the number of sheep
        Sheep = atoi(numlist[0]);

        // Parse the second element to get the number of wolves
        Wolve = atoi(numlist[1]);

        // Check if the number of wolves is greater than or equal to the number of sheep
        if (Wolve >= Sheep) {
            printf("unsafe\n");
        } else {
            printf("safe\n");
        }
    }

    return 0;
}

