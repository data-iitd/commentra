#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000
#define INF 100000000

typedef struct {
    int index;
    int p1, p2;
} pair;

typedef struct {
    pair *data;
    int size;
    int capacity;
} pairs;

typedef struct {
    int *data;
    int size;
    int capacity;
} Int64Slice;

typedef struct {
    char **data;
    int size;
    int capacity;
} stringArray;

int di[] = {-1, 0, 1, 0}; // Direction vectors for row movement
int dj[] = {0, -1, 0, 1}; // Direction vectors for column movement

char buffer[INITIAL_BUF_SIZE];
int bufferIndex = 0;

void initializeBuffer() {
    fread(buffer, 1, INITIAL_BUF_SIZE, stdin);
    bufferIndex = 0;
}

char getChar() {
    if (bufferIndex >= INITIAL_BUF_SIZE) {
        initializeBuffer();
    }
    return buffer[bufferIndex++];
}

int readInt() {
    int num = 0;
    char ch = getChar();
    while (ch < '0' || ch > '9') {
        ch = getChar();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + (ch - '0');
        ch = getChar();
    }
    return num;
}

float readFloat() {
    float num = 0.0;
    int decimal = 0;
    int sign = 1;
    char ch = getChar();
    while (ch != '-' && (ch < '0' || ch > '9')) {
        ch = getChar();
    }
    if (ch == '-') {
        sign = -1;
        ch = getChar();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + (ch - '0');
        ch = getChar();
    }
    if (ch == '.') {
        ch = getChar();
        while (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
            decimal = decimal * 10 + 1;
            ch = getChar();
        }
    }
    return sign * num / decimal;
}

char readChar() {
    char ch = getChar();
    while (ch == ' ' || ch == '\n' || ch == '\t') {
        ch = getChar();
    }
    return ch;
}

char* readLine() {
    int capacity = 100;
    char *line = (char*)malloc(capacity * sizeof(char));
    int length = 0;
    char ch = getChar();
    while (ch != '\n' && ch != EOF) {
        if (length >= capacity) {
            capacity *= 2;
            line = (char*)realloc(line, capacity * sizeof(char));
        }
        line[length++] = ch;
        ch = getChar();
    }
    line[length] = '\0';
    return line;
}

void write(const char *s) {
    fputs(s, stdout);
}

void print() {
    fflush(stdout);
}

void initializePairs(pairs *p, int capacity) {
    p->data = (pair*)malloc(capacity * sizeof(pair));
    p->size = 0;
    p->capacity = capacity;
}

void addPair(pairs *p, int index, int p1, int p2) {
    if (p->size >= p->capacity) {
        p->capacity *= 2;
        p->data = (pair*)realloc(p->data, p->capacity * sizeof(pair));
    }
    p->data[p->size].index = index;
    p->data[p->size].p1 = p1;
    p->data[p->size].p2 = p2;
    p->size++;
}

void sortPairs(pairs *p) {
    qsort(p->data, p->size, sizeof(pair), (int (*)(const void*, const void*))comparePairs);
}

int comparePairs(const pair *a, const pair *b) {
    return a->index - b->index;
}

void initializeInt64Slice(Int64Slice *s, int capacity) {
    s->data = (int*)malloc(capacity * sizeof(int));
    s->size = 0;
    s->capacity = capacity;
}

void addInt64(Int64Slice *s, int value) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
    }
    s->data[s->size++] = value;
}

void sortInt64Slice(Int64Slice *s) {
    qsort(s->data, s->size, sizeof(int), (int (*)(const void*, const void*))compareInt64);
}

int compareInt64(const int *a, const int *b) {
    return *a - *b;
}

void initializeStringArray(stringArray *sa, int capacity) {
    sa->data = (char**)malloc(capacity * sizeof(char*));
    sa->size = 0;
    sa->capacity = capacity;
}

void addString(stringArray *sa, const char *s) {
    if (sa->size >= sa->capacity) {
        sa->capacity *= 2;
        sa->data = (char**)realloc(sa->data, sa->capacity * sizeof(char*));
    }
    sa->data[sa->size] = (char*)malloc((strlen(s) + 1) * sizeof(char));
    strcpy(sa->data[sa->size], s);
    sa->size++;
}

void freeStringArray(stringArray *sa) {
    for (int i = 0; i < sa->size; i++) {
        free(sa->data[i]);
    }
    free(sa->data);
}

int main() {
    int A = readInt();
    int B = readInt();
    int C = readInt();
    
    if (C >= A && C <= B) {
        write("Yes\n");
    } else {
        write("No\n");
    }
    print();
    return 0;
}

