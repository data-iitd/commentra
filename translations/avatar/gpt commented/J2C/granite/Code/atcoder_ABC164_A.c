
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a character array to store the input line
    char line[100];
    
    // Initializing an array to store the input strings
    char *scList[100];
    
    // Initializing a counter for the number of input lines
    int i = 0;
    
    // Continuously read input lines until an exception occurs (e.g., EOF)
    while (fgets(line, sizeof(line), stdin)) {
        // Trimming the newline character from the input line
        line[strcspn(line, "\n")] = 0;
        
        // Adding the input line to the array
        scList[i] = strdup(line);
        
        // Incrementing the counter
        i++;
    }
    
    // Splitting the first line of input into an array of strings
    char *numlist[2];
    char *token = strtok(scList[0], " ");
    int j = 0;
    while (token!= NULL) {
        numlist[j] = token;
        token = strtok(NULL, " ");
        j++;
    }
    
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
    
    // Freeing the memory allocated for the input lines
    for (int k = 0; k < i; k++) {
        free(scList[k]);
    }
    
    return 0;
}
