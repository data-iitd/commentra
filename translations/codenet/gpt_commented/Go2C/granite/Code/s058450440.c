
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables to store counts and the result
int a[5]; // Array to hold counts of specific characters
int ans = 0; // Variable to hold the final answer

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
    // If no more characters left to choose, add the result to ans
    if (left == 0) {
        ans += res;
        return;
    }
    // Iterate through the array starting from index i
    for (int j = i; j < 5; j++) {
        // Recursive call to dfs with one less character to choose
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    // Initialize input reader
    struct io *io = newIo();
    // Read the number of characters
    int n = io->nextInt();
    // Map to count occurrences of specific characters
    int dic[5] = {0};

    // Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
    for (int i = 0; i < n; i++) {
        char c = io->nextString()[0]; // Read the first character of the string
        switch (c) {
            case 'M':
            case 'A':
            case 'R':
            case 'C':
            case 'H':
                dic[c - 'A']++; // Increment count for the character if it's one of the specified
                break;
        }
    }

    // Populate the array a with the counts from the dictionary
    int k = 0;
    for (int i = 0; i < 5; i++) {
        if (dic[i] > 0) {
            a[k++] = dic[i]; // Add the count to the array if it's non-zero
        }
    }

    // Start the DFS to calculate the product of combinations of 3 characters
    dfs(3, 0, 1);
    // Print the final result
    printf("%d\n", ans);
    return 0;
}

// Struct to handle input operations
struct io {
    char buffer[1024]; // Buffer to hold input data
    char *tokens[100]; // Array to hold split input tokens
    int nextToken; // Index for the next token to read
    FILE *reader; // Pointer to the input file
};

// Function to create a new io instance
struct io *newIo() {
    struct io *io = (struct io *)malloc(sizeof(struct io)); // Allocate memory for the io struct
    io->reader = stdin; // Set the input file to stdin
    io->nextToken = 0; // Reset the token index
    return io; // Return the new io instance
}

// Method to read the next line of input
char *nextLine(struct io *io) {
    fgets(io->buffer, 1024, io->reader); // Read a line from input
    char *line = (char *)malloc(strlen(io->buffer) + 1); // Allocate memory for the line
    strcpy(line, io->buffer); // Copy the line from the buffer
    return line; // Return the line
}

// Method to read the next string token from input
char *nextString(struct io *io) {
    // Load more tokens if the current index exceeds the available tokens
    while (io->nextToken >= 100) {
        free(io->tokens[0]); // Free the memory allocated for the previous token
        for (int i = 0; i < 99; i++) {
            io->tokens[i] = io->tokens[i + 1]; // Shift the tokens to the left
        }
        io->tokens[99] = nextLine(io); // Read the next line and store it in the last token
        io->nextToken = 0; // Reset the token index
    }
    char *r = io->tokens[io->nextToken]; // Get the next token
    io->nextToken++; // Move to the next token
    return r; // Return the token
}

// Method to read the next integer from input
int nextInt(struct io *io) {
    int i;
    sscanf(nextString(io), "%d", &i); // Convert the next string token to an integer
    return i; // Return the integer
}

// END-OF-CODE