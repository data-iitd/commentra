#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 100000000
#define INF 100000000

typedef struct {
    int64_t index;
    int64_t p1, p2;
} pair;

typedef struct {
    pair* data;
    int size;
    int capacity;
} pairs;

void init_pairs(pairs* p, int capacity) {
    p->data = (pair*)malloc(capacity * sizeof(pair));
    p->size = 0;
    p->capacity = capacity;
}

void add_pair(pairs* p, int64_t index, int64_t p1, int64_t p2) {
    if (p->size >= p->capacity) {
        p->capacity *= 2;
        p->data = (pair*)realloc(p->data, p->capacity * sizeof(pair));
    }
    p->data[p->size].index = index;
    p->data[p->size].p1 = p1;
    p->data[p->size].p2 = p2;
    p->size++;
}

void free_pairs(pairs* p) {
    free(p->data);
}

typedef struct {
    int64_t* data;
    int size;
} Int64Slice;

void init_int64slice(Int64Slice* slice, int capacity) {
    slice->data = (int64_t*)malloc(capacity * sizeof(int64_t));
    slice->size = 0;
}

void add_int64(Int64Slice* slice, int64_t value) {
    if (slice->size >= MAX_BUF_SIZE) {
        slice->data = (int64_t*)realloc(slice->data, (slice->size + 1) * sizeof(int64_t));
    }
    slice->data[slice->size] = value;
    slice->size++;
}

void free_int64slice(Int64Slice* slice) {
    free(slice->data);
}

void sort_int64slice(Int64Slice* slice) {
    qsort(slice->data, slice->size, sizeof(int64_t), (int (*)(const void*, const void*))compare_int64);
}

int compare_int64(const int64_t* a, const int64_t* b) {
    return (*a > *b) - (*a < *b);
}

int64_t read_int() {
    int64_t value;
    scanf("%ld", &value);
    return value;
}

double read_float() {
    double value;
    scanf("%lf", &value);
    return value;
}

char* read_line() {
    char* line = (char*)malloc(INITIAL_BUF_SIZE * sizeof(char));
    if (fgets(line, INITIAL_BUF_SIZE, stdin) != NULL) {
        return line;
    } else {
        free(line);
        return NULL;
    }
}

void write(const char* s) {
    printf("%s", s);
}

void print() {
    fflush(stdout);
}

int main() {
    int64_t A = read_int();
    int64_t B = read_int();
    int64_t C = read_int();
    if (C >= A && C <= B) {
        write("Yes\n");
    } else {
        write("No\n");
    }
    print();
    return 0;
}

