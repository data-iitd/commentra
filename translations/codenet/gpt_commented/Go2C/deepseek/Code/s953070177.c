#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getNextString retrieves the next string from the input.
char* getNextString() {
    char *line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}

// getNextInt converts the next string from the input to an integer.
int getNextInt() {
    char *str = getNextString();
    if (str == NULL) {
        return -1; // Error or end of input
    }
    int result = atoi(str);
    free(str);
    return result;
}

// getNextInt64 converts the next string from the input to a 64-bit integer.
long long getNextInt64() {
    char *str = getNextString();
    if (str == NULL) {
        return -1; // Error or end of input
    }
    long long result = atoll(str);
    free(str);
    return result;
}

// absint returns the absolute value of an integer.
int absint(int a) {
    return a < 0 ? -a : a;
}

int main() {
    // Determine the input source: standard input or a file specified as a command-line argument.
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Initialize the buffered reader for input.
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the number of elements from the input.
    int n = getNextInt();

    // Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
    int aa[n+2];
    int sum = 0;

    // Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
    for (int i = 0; i < n; i++) {
        aa[i+1] = getNextInt();
        sum += absint(aa[i+1] - aa[i]);
    }
    // Include the difference between the last element and the element before it.
    sum += absint(aa[n+1] - aa[n]);

    // Calculate and print the result for each element.
    for (int i = 1; i < n+1; i++) {
        // Calculate the new sum of absolute differences if the i-th element is removed.
        int ans = sum - absint(aa[i+1]-aa[i]) - absint(aa[i]-aa[i-1]) + absint(aa[i+1]-aa[i-1]);
        printf("%d\n", ans); // Output the result for the current element.
    }

    // Free resources and close the file if necessary.
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}
