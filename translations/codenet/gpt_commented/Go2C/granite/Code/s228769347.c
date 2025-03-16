
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
FILE *getScanner(FILE *fp) {
    setbuf(fp, NULL); // Set the buffer size to 0 for unbuffered input.
    return fp;
}

// getNextString reads the next word from the scanner and returns it as a string.
char *getNextString(FILE *scanner) {
    int c = getc(scanner); // Read the next character.
    if (c == EOF) {
        return NULL; // Return NULL if end of file is reached.
    }
    char *str = (char *)malloc(sizeof(char) * 500001); // Allocate memory for the string.
    int i = 0; // Initialize the index for the string.
    while (c!='' && c!= '\n' && c!= EOF) { // Read characters until a space or newline is encountered.
        str[i++] = (char)c; // Store the character in the string.
        c = getc(scanner); // Read the next character.
    }
    str[i] = '\0'; // Null-terminate the string.
    return str; // Return the string.
}

// getNextInt converts the next word from the scanner to an integer and returns it.
int getNextInt(FILE *scanner) {
    char *str = getNextString(scanner); // Read the next word from the scanner.
    int i = 0; // Initialize the index for the string.
    int result = 0; // Initialize the result variable.
    while (str[i]!= '\0') { // Iterate through each character in the string.
        result = result * 10 + (str[i] - '0'); // Convert the character to an integer and add it to the result.
        i++; // Increment the index.
    }
    free(str); // Free the memory allocated for the string.
    return result; // Return the integer.
}

// getNextInt64 converts the next word from the scanner to an int64 and returns it.
int64_t getNextInt64(FILE *scanner) {
    char *str = getNextString(scanner); // Read the next word from the scanner.
    int i = 0; // Initialize the index for the string.
    int64_t result = 0; // Initialize the result variable.
    while (str[i]!= '\0') { // Iterate through each character in the string.
        result = result * 10 + (str[i] - '0'); // Convert the character to an int64 and add it to the result.
        i++; // Increment the index.
    }
    free(str); // Free the memory allocated for the string.
    return result; // Return the int64.
}

// getNextUint64 converts the next word from the scanner to a uint64 and returns it.
uint64_t getNextUint64(FILE *scanner) {
    char *str = getNextString(scanner); // Read the next word from the scanner.
    int i = 0; // Initialize the index for the string.
    uint64_t result = 0; // Initialize the result variable.
    while (str[i]!= '\0') { // Iterate through each character in the string.
        result = result * 10 + (str[i] - '0'); // Convert the character to a uint64 and add it to the result.
        i++; // Increment the index.
    }
    free(str); // Free the memory allocated for the string.
    return result; // Return the uint64.
}

// getNextFloat64 converts the next word from the scanner to a float64 and returns it.
double getNextFloat64(FILE *scanner) {
    char *str = getNextString(scanner); // Read the next word from the scanner.
    int i = 0; // Initialize the index for the string.
    double result = 0; // Initialize the result variable.
    int decimalPlace = 0; // Initialize the decimal place counter.
    int isDecimal = 0; // Initialize the flag for decimal place.
    while (str[i]!= '\0') { // Iterate through each character in the string.
        if (str[i] == '.') { // Check if the character is a decimal point.
            isDecimal = 1; // Set the flag for decimal place.
            continue; // Skip the character.
        }
        result = result * 10 + (str[i] - '0'); // Convert the character to a float64 and add it to the result.
        if (isDecimal) { // If the character is a decimal place, increment the decimal place counter.
            decimalPlace++;
        }
        i++; // Increment the index.
    }
    free(str); // Free the memory allocated for the string.
    return result / pow(10, decimalPlace); // Return the float64 with the correct decimal place.
}

int main() {
    FILE *fp = stdin; // Default input is standard input.
    FILE *wfp = stdout; // Default output is standard output.

    // Check for command-line arguments to read from a file and write to a file.
    if (argc > 1) {
        fp = fopen(argv[1], "r"); // Open the input file if provided.
        if (argc > 2) {
            wfp = fopen(argv[2], "w"); // Create the output file if provided.
        }
    }

    FILE *scanner = getScanner(fp); // Initialize the scanner for input.
    FILE *writer = fopencookie(wfp, "w", stdout); // Create a buffered writer for output.

    int n = getNextInt(scanner); // Read the number of integers.
    int ll[n]; // Create a slice to hold the integers.

    // Read n integers from the input.
    for (int i = 0; i < n; i++) {
        ll[i] = getNextInt(scanner); // Populate the slice with integers.
    }

    qsort(ll, n, sizeof(int), compare); // Sort the slice of integers.

    int ans = 0; // Initialize the answer counter.
    // Iterate through pairs of integers to find valid triplets.
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1; // Start searching for the third element after the second element.
            int r = n; // Set the right boundary for binary search.
            // Perform binary search to find the count of valid third elements.
            while (l < r) {
                int m = (l + r) / 2; // Calculate the middle index.
                if (ll[m] < ll[i] + ll[j]) { // Check if the sum of the first two is greater than the middle element.
                    l = m + 1; // Move the left boundary up.
                    continue;
                }
                r = m; // Move the right boundary down.
            }
            // Count the number of valid third elements.
            ans += l - (j + 1); // Update the answer with the count of valid triplets.
        }
    }
    fprintf(writer, "%d\n", ans); // Print the result to the output.

    fclose(writer); // Close the output file.
    return 0; // Return 0 to indicate successful execution.
}

