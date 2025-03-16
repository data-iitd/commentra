#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 512000

// Initialize a buffer for reading input
char inputBuffer[BUFFERSIZE];
int inputBufferIndex = 0;
int inputBufferLength = 0;

// Initialize a buffer for output
char outputBuffer[BUFFERSIZE];
int outputBufferIndex = 0;

// Method to read the next character from the input buffer
int readChar() {
    if (inputBufferIndex >= inputBufferLength) {
        inputBufferLength = fread(inputBuffer, 1, BUFFERSIZE, stdin);
        inputBufferIndex = 0;
    }
    return inputBuffer[inputBufferIndex++];
}

// Method to read the next token from the input buffer
char* readToken() {
    static char token[100000];
    int i = 0;
    int c;
    while ((c = readChar()) != ' ' && c != '\n') {
        token[i++] = c;
    }
    token[i] = '\0';
    return token;
}

// Method to read the next integer from the input buffer
int readInt() {
    char* token = readToken();
    return atoi(token);
}

// Method to read the next double from the input buffer
double readDouble() {
    char* token = readToken();
    return atof(token);
}

// Method to read the next long from the input buffer
long long readLong() {
    char* token = readToken();
    return atoll(token);
}

// Method to write a character to the output buffer
void writeChar(char c) {
    if (outputBufferIndex >= BUFFERSIZE) {
        fwrite(outputBuffer, 1, BUFFERSIZE, stdout);
        outputBufferIndex = 0;
    }
    outputBuffer[outputBufferIndex++] = c;
}

// Method to write a string to the output buffer
void writeString(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        writeChar(str[i]);
    }
}

// Method to write the next integer to the output buffer
void writeInt(int num) {
    char buffer[20];
    sprintf(buffer, "%d", num);
    writeString(buffer);
}

// Method to write the next double to the output buffer
void writeDouble(double num) {
    char buffer[40];
    sprintf(buffer, "%f", num);
    writeString(buffer);
}

// Method to write the next long to the output buffer
void writeLong(long long num) {
    char buffer[30];
    sprintf(buffer, "%lld", num);
    writeString(buffer);
}

// Method to solve the main problem
void solve() {
    // Read the position from input
    long long position = readLong();
    
    // Initialize the nearest sequence start index
    long long nrstSeqStartIndx = 1;
    
    // Find the nearest sequence start index such that its value is less than the position
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }
    
    // Increment the nearest sequence start index until its value exceeds the position
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }
    
    // Get the starting index value for the nearest sequence
    long long startIndex = getValueAtIndex(nrstSeqStartIndx);
    
    // Output the result, which is the difference between the position and the start index plus one
    writeLong((position - startIndex) + 1);
    writeChar('\n');
}

// Method to calculate the value at a given index based on a specific formula
long long getValueAtIndex(long long index) {
    return 1 + ((index - 1) * index / 2);
}

// Main method to execute the program
int main() {
    // Initialize the input buffer
    fread(inputBuffer, 1, BUFFERSIZE, stdin);
    
    // Call the solve method to process the input and produce output
    solve();
    
    // Flush the output buffer
    fwrite(outputBuffer, 1, outputBufferIndex, stdout);
    
    return 0;
}

