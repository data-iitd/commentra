#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declaring a character array to store the input line
    char input[1000];
    
    // Declaring an array of strings to store the input lines
    char *scList[1000];
    int index = 0;

    // Continuously read input lines until EOF
    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Allocating memory for the current input line
        scList[index] = (char *)malloc((strlen(input) + 1) * sizeof(char));
        // Copying the input line to the allocated memory
        strcpy(scList[index], input);
        // Incrementing the index
        index++;
    }

    // Splitting the first line of input into an array of strings
    char *numlist[2];
    numlist[0] = strtok(scList[0], " ");
    numlist[1] = strtok(NULL, " ");

    // Parsing the first number as the count of sheep
    int Sheep = atoi(numlist[0]);
    
    // Parsing the second number as the count of wolves
    int Wolve = atoi(numlist[1]);

    // Checking if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        // If wolves are greater than or equal to sheep, it's unsafe
        printf("unsafe\n");
    } else {
        // If wolves are fewer than sheep, it's safe
        printf("safe\n");
    }

    // Freeing the allocated memory for each input line
    for (int i = 0; i < index; i++) {
        free(scList[i]);
    }

    return 0;
}
