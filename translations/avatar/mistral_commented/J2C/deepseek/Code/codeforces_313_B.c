#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare file pointers
    FILE *inputFile, *outputFile;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    // Check if files are opened successfully
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read input from the file
    char line[1000];
    fgets(line, sizeof(line), inputFile);

    // Process the input (example: counting words)
    int wordCount = 0;
    char *token = strtok(line, " \t\n\r\f\v");
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " \t\n\r\f\v");
    }

    // Write output to the file
    fprintf(outputFile, "Word count: %d\n", wordCount);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
