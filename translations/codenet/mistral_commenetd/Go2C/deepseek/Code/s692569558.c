#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char ds[1000]; // Buffer to store the input string
    char *dd[1000]; // Array of pointers to store the split strings
    int dn[1000]; // Array to store the integer values
    int sum = 0; // Variable to store the sum of products
    int i, j, k; // Loop variables

    // Read the first two lines from standard input
    fgets(ds, sizeof(ds), stdin);
    fgets(ds, sizeof(ds), stdin);

    // Split the string ds into an array of strings dd using strtok function
    char *token = strtok(ds, " ");
    k = 0;
    while (token != NULL) {
        dd[k] = token;
        token = strtok(NULL, " ");
        k++;
    }

    // Convert each string in dd to an integer and store it in dn
    for (i = 0; i < k; i++) {
        dn[i] = atoi(dd[i]);
    }

    // Calculate the sum of products
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {
            sum += dn[i] * dn[j];
        }
    }

    // Print the value of sum to the standard output
    printf("%d\n", sum);

    // End of code
    return 0;
}

