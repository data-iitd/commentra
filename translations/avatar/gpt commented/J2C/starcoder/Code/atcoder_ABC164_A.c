#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the console
    char input[1000];
    scanf("%[^\n]%*c", input);

    // Initializing an ArrayList to store the input strings
    char *scList[1000];

    // Continuously read input lines until an exception occurs (e.g., EOF)
    for (int i = 0; i >= 0; i++) {
        if (scanf("%[^\n]%*c", input) == 0) {
            break;
        }
        scList[i] = malloc(sizeof(char) * (strlen(input) + 1));
        strcpy(scList[i], input);
    }

    // Splitting the first line of input into an array of strings
    char *numlist[1000];
    numlist = strtok(scList[0], " ");

    // Parsing the first number as the count of sheep
    int Sheep = atoi(numlist[0]);

    // Parsing the second number as the count of wolves
    int Wolve = atoi(numlist[1]);

    // Checking if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        // If wolves are greater than or equal to sheep, it's unsafe
        printf("unsafe");
    } else {
        // If wolves are fewer than sheep, it's safe
        printf("safe");
    }

    return 0;
}

