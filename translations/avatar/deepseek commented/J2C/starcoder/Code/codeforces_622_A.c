#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 512000

// Step 2: Define the Scanner and PrintWriter for input and output operations.
typedef struct {
    char *buffer;
    char *ptr;
    char *end;
} Scanner;

typedef struct {
    FILE *file;
    char *buffer;
    size_t size;
    size_t length;
} PrintWriter;

Scanner sc;
PrintWriter out;

// Step 3: Implement the solve method to find the position of a given value in a sequence.
void solve() {
    long position = sc.nextLong();
    long nrstSeqStartIndx = 1;

    // Step 4: Find the starting index of the sequence where the position might be located.
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }

    // Step 4: Find the exact position within the sequence.
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }

    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    out.println((position - startIndex) + 1);
}

// Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

// Step 5: Implement the main method to initialize the input and call the solve method.
int main(int argc, char *argv[]) {
    // Step 7: Initialize the input reader for the in class.
    in_init();
    solve();
    out_close();
    return 0;
}

// Step 7: Implement the in class to handle input operations.
void in_init() {
    sc.buffer = (char *) malloc(BUFFERSIZE);
    sc.ptr = sc.buffer;
    sc.end = sc.buffer + BUFFERSIZE;
    fread(sc.buffer, 1, BUFFERSIZE, stdin);
}

char *in_next() {
    while (sc.ptr >= sc.end) {
        sc.buffer = (char *) realloc(sc.buffer, BUFFERSIZE);
        sc.ptr = sc.buffer + strlen(sc.buffer);
        fread(sc.ptr, 1, BUFFERSIZE, stdin);
        sc.end = sc.buffer + BUFFERSIZE;
    }
    char *ret = sc.ptr;
    sc.ptr++;
    return ret;
}

long in_nextLong() {
    return atol(in_next());
}

void out_init() {
    out.file = stdout;
    out.buffer = (char *) malloc(BUFFERSIZE);
    out.size = BUFFERSIZE;
    out.length = 0;
}

void out_print(char *str) {
    while (out.length + strlen(str) >= out.size) {
        out.size *= 2;
        out.buffer = (char *) realloc(out.buffer, out.size);
    }
    strcpy(out.buffer + out.length, str);
    out.length += strlen(str);
}

void out_println(char *str) {
    out_print(str);
    out_print("\n");
}

void out_close() {
    fwrite(out.buffer, 1, out.length, out.file);
    free(out.buffer);
}

