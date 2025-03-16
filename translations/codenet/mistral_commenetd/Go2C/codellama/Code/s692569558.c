
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize a new scanner for reading from standard input
    char *s = malloc(sizeof(char) * 1000);
    scanf("%s", s);
    scanf("%s", s);

    // Assign the text of the second line to the variable ds
    char *ds = s;

    // Split the string ds into an array of strings dd using the strings.Split function
    char *dd[1000];
    int i = 0;
    char *token = strtok(ds, " ");
    while (token != NULL) {
        dd[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    // Create a new slice dn of length len(dd) and initialize each element to 0 using make function
    int dn[1000];
    for (i = 0; i < 1000; i++) {
        dn[i] = 0;
    }

    // Iterate through each element i in the slice dd and convert its string value to integer using strconv.Atoi function and store it in the corresponding index of slice dn
    for (i = 0; i < 1000; i++) {
        dn[i] = atoi(dd[i]);
    }

    // Initialize sum variable to 0
    int sum = 0;

    // Iterate through each index i in the slice dn
    for (i = 0; i < 1000; i++) {
        // Iterate through each index j greater than i in the slice dn
        for (int j = i + 1; j < 1000; j++) {
            // Add the product of dn[i] and dn[j] to the sum variable
            sum += dn[i] * dn[j];
        }
    }

    // Print the value of sum variable to the standard output using printf function
    printf("%d\n", sum);

    // End of code
    return 0;
}

