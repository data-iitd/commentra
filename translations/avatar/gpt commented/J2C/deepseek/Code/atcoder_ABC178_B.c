#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FastReader structure to handle fast input
typedef struct {
    FILE *fp;
    char buffer[1024];
    int bufferIndex;
    int bufferSize;
} FastReader;

// Function to initialize FastReader
FastReader* createFastReader(const char* input) {
    FastReader* reader = (FastReader*)malloc(sizeof(FastReader));
    reader->fp = fmemopen((void*)input, strlen(input), "r");
    reader->bufferIndex = 0;
    reader->bufferSize = 0;
    return reader;
}

// Function to read the next token from input
char* next(FastReader* reader) {
    // Skip any leading whitespace
    while (reader->bufferIndex < reader->bufferSize && isspace(reader->buffer[reader->bufferIndex])) {
        reader->bufferIndex++;
    }
    
    // If no more characters are available, return NULL
    if (reader->bufferIndex >= reader->bufferSize) {
        return NULL;
    }
    
    // Read the next token
    char* token = reader->buffer + reader->bufferIndex;
    while (reader->bufferIndex < reader->bufferSize && !isspace(reader->buffer[reader->bufferIndex])) {
        reader->bufferIndex++;
    }
    
    // Null-terminate the token
    reader->buffer[reader->bufferIndex] = '\0';
    
    return token;
}

// Function to read the next integer from input
int nextInt(FastReader* reader) {
    char* token = next(reader);
    return token ? atoi(token) : 0;
}

// Function to read the next long from input
long nextLong(FastReader* reader) {
    char* token = next(reader);
    return token ? atol(token) : 0;
}

// Function to read the next double from input
double nextDouble(FastReader* reader) {
    char* token = next(reader);
    return token ? atof(token) : 0.0;
}

// Function to read the next line from input
char* nextLine(FastReader* reader) {
    char* line = NULL;
    size_t len = 0;
    if (getline(&line, &len, reader->fp) != -1) {
        return line;
    }
    free(line);
    return NULL;
}

// Function to compute (x^y) % mod using modular exponentiation
int modPower(int x, int y, int mod) {
    int res = 1;
    x %= mod; // Reduce x modulo mod
    if (x == 0) return 0; // If x is 0, return 0
    
    // Loop until y becomes 0
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1; // Divide y by 2
        x = (x * x) % mod; // Square x
    }
    return res; // Return the final result
}

// Pair structure to hold two related values
typedef struct {
    int first;
    int second;
} pair;

// Function to initialize the pair
pair* createPair(int first, int second) {
    pair* p = (pair*)malloc(sizeof(pair));
    p->first = first;
    p->second = second;
    return p;
}

// Main function to execute the program
int main() {
    FastReader* reader = createFastReader("1 2 3 4"); // Create an instance of FastReader
    long a[4]; // Array to hold four long integers
    
    // Read four long integers from input
    for (int i = 0; i < 4; i++) {
        a[i] = nextLong(reader);
    }
    
    // Calculate and print the maximum product of pairs from the array
    long maxProduct = a[0] * a[2];
    if (a[1] * a[3] > maxProduct) maxProduct = a[1] * a[3];
    if (a[0] * a[3] > maxProduct) maxProduct = a[0] * a[3];
    if (a[1] * a[2] > maxProduct) maxProduct = a[1] * a[2];
    
    printf("%ld\n", maxProduct);
    
    // Free resources
    fclose(reader->fp);
    free(reader);
    
    return 0;
}
