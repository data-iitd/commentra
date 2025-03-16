#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Reading the number of strings 'num' from the user input
    int num;
    scanf("%d", &num);

    // Allocating memory for an array of strings
    char **arr = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each string is 100
        scanf("%s", arr[i]);
    }

    // Initializing two variables 'counter' and 'fine'
    int counter = 0;
    int fine = 0;

    // The first nested loop to iterate through each character in each string
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < strlen(arr[i]); k++) {
            // Checking if the character at position (i,k) in the string at index 'i' is 'C'
            if (arr[i][k] == 'C') {
                // Incrementing the counter variable
                counter++;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) / 2;
        // Resetting the counter variable for the next string
        counter = 0;
    }

    // The second nested loop to iterate through each character in each string again
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            // Checking if the character at position (i,k) in the string at index 'k' is 'C'
            if (arr[k][i] == 'C') {
                // Incrementing the counter variable
                counter++;
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) / 2;
        // Resetting the counter variable for the next string
        counter = 0;
    }

    // Printing the final result 'fine'
    printf("%d\n", fine);

    // Freeing allocated memory
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// <END-OF-CODE>
