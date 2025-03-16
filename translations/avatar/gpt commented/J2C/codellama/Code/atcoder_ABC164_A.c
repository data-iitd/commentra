#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the console
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int Sheep, Wolve;

    // Continuously read input lines until an exception occurs (e.g., EOF)
    while ((read = getline(&line, &len, stdin)) != -1) {
        // Splitting the first line of input into an array of strings
        char *numlist[2];
        numlist[0] = strtok(line, " ");
        numlist[1] = strtok(NULL, " ");

        // Parsing the first number as the count of sheep
        Sheep = atoi(numlist[0]);

        // Parsing the second number as the count of wolves
        Wolve = atoi(numlist[1]);

        // Checking if the number of wolves is greater than or equal to the number of sheep
        if (Wolve >= Sheep) {
            // If wolves are greater than or equal to sheep, it's unsafe
            printf("unsafe\n");
        } else {
            // If wolves are fewer than sheep, it's safe
            printf("safe\n");
        }
    }

    // Freeing the memory allocated by getline()
    free(line);

    // Ending the program with comment "