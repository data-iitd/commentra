#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Structure to represent the Scanner
typedef struct {
    FILE *file;
    char buffer[1000];
    int position;
} Scanner;

// Function to initialize a new Scanner
Scanner* NewScanner() {
    Scanner *s = (Scanner*)malloc(sizeof(Scanner));
    s->file = stdin;
    s->position = 0;
    return s;
}

// Function to read the next token
char* Next(Scanner *s) {
    while (s->position < strlen(s->buffer) && s->buffer[s->position] == ' ') {
        s->position++;
    }
    int start = s->position;
    while (s->position < strlen(s->buffer) && s->buffer[s->position] != ' ') {
        s->position++;
    }
    char *result = (char*)malloc(s->position - start + 1);
    strncpy(result, s->buffer + start, s->position - start);
    result[s->position - start] = '\0';
    return result;
}

// Function to read the next line
char* NextLine(Scanner *s) {
    while (s->position < strlen(s->buffer) && s->buffer[s->position] == ' ') {
        s->position++;
    }
    int start = s->position;
    while (s->position < strlen(s->buffer) && s->buffer[s->position] != '\n') {
        s->position++;
    }
    char *result = (char*)malloc(s->position - start + 1);
    strncpy(result, s->buffer + start, s->position - start);
    result[s->position - start] = '\0';
    return result;
}

// Function to read the next integer
int NextInt(Scanner *s) {
    char *token = Next(s);
    int value = atoi(token);
    free(token);
    return value;
}

// Function to read the next integer (64-bit)
long long NextInt64(Scanner *s) {
    char *token = Next(s);
    long long value = atoll(token);
    free(token);
    return value;
}

// Function to read the next float
double NextFloat(Scanner *s) {
    char *token = Next(s);
    double value = atof(token);
    free(token);
    return value;
}

// Function to read the next array of integers
int* NextIntArray(Scanner *s) {
    char *line = NextLine(s);
    char *token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(line);
    s->position = 0;
    line = NextLine(s);
    token = strtok(line, " ");
    int *result = (int*)malloc(count * sizeof(int));
    int i = 0;
    while (token != NULL) {
        result[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
    return result;
}

// Main function
int main() {
    Scanner *sc = NewScanner();
    int H = NextInt(sc);
    int W = NextInt(sc);
    int N = NextInt(sc);
    int A = max(H, W);
    printf("%d\n", (N + A - 1) / A);
    free(sc);
    return 0;
}

