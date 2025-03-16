
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform Depth First Search (DFS) algorithm
void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }

    for (int j = i; j < len; j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    // Initializing an io object for input/output handling
    struct io *io = newIo();

    // Reading the number of test cases
    int n = io->nextInt();

    // Initializing an empty map to store the frequency of each character
    int dic[256] = {0};

    // Reading strings and updating the map
    for (int i = 0; i < n; i++) {
        char c = io->nextString()[0];
        switch (c) {
            case 'M':
            case 'A':
            case 'R':
            case 'C':
            case 'H':
                dic[c]++;
                break;
        }
    }

    // Converting map values to integers and appending them to the 'a' slice
    int len = 0;
    for (int i = 0; i < 256; i++) {
        if (dic[i] > 0) {
            a[len] = dic[i];
            len++;
        }
    }

    // Calling the 'dfs' function with initial arguments
    dfs(3, 0, 1);

    // Printing the answer
    printf("%d\n", ans);

    return 0;
}

// Struct definition for input/output handling
struct io {
    char buffer[1024];
    char *tokens[1024];
    int nextToken;
    FILE *reader;
};

// Function to initialize the io object
struct io *newIo() {
    struct io *io = (struct io *)malloc(sizeof(struct io));
    io->reader = stdin;
    io->nextToken = 0;
    return io;
}

// Function to read a line from the standard input
char *nextLine(struct io *io) {
    fgets(io->buffer, 1024, io->reader);
    return io->buffer;
}

// Function to read a token (a word) from the standard input
char *nextString(struct io *io) {
    if (io->nextToken >= 1024) {
        nextLine(io);
        io->nextToken = 0;
    }
    char *token = io->tokens[io->nextToken];
    if (token == NULL) {
        token = strsep(&io->buffer, " ");
        io->tokens[io->nextToken] = token;
    }
    io->nextToken++;
    return token;
}

// Function to convert a token (a string) to an integer
int nextInt(struct io *io) {
    char *token = nextString(io);
    int number = atoi(token);
    return number;
}

// 

