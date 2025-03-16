#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for atoi function

int main() {  // Main function definition
    char input[100];  // Buffer to store input line
    int Sheep, Wolve;  // Variables to store the number of sheep and wolves

    // Reading the first line of input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Parsing the input line to extract the number of sheep and wolves
        sscanf(input, "%d %d", &Sheep, &Wolve);  // Using sscanf to read two integers from the input
    }

    // Checking if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        printf("unsafe\n");  // Printing "unsafe" if wolves are greater than or equal to sheep
    } else {
        printf("safe\n");  // Printing "safe" if sheep are greater than wolves
    }

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
