#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// I/O
typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_pos;
} Scanner;

Scanner* new_scanner() {
    Scanner *sc = (Scanner*)malloc(sizeof(Scanner));
    sc->buffer_size = 1024;
    sc->buffer = (char*)malloc(sc->buffer_size);
    sc->buffer_pos = 0;
    fread(sc->buffer, sizeof(char), sc->buffer_size, stdin);
    return sc;
}

char next_char(Scanner *sc) {
    if (sc->buffer_pos >= sc->buffer_size) {
        fread(sc->buffer, sizeof(char), sc->buffer_size, stdin);
        sc->buffer_pos = 0;
    }
    return sc->buffer[sc->buffer_pos++];
}

int next_int(Scanner *sc) {
    char c;
    while (isspace(c = next_char(sc)));
    int num = 0;
    while (isdigit(c)) {
        num = num * 10 + (c - '0');
        c = next_char(sc);
    }
    return num;
}

double next_float(Scanner *sc) {
    char c;
    while (isspace(c = next_char(sc)));
    int num = 0;
    double denom = 1.0;
    while (isdigit(c)) {
        num = num * 10 + (c - '0');
        c = next_char(sc);
    }
    if (c == '.') {
        c = next_char(sc);
        while (isdigit(c)) {
            denom *= 10.0;
            num = num * 10 + (c - '0');
            c = next_char(sc);
        }
    }
    return (double)num / denom;
}

char* next_str(Scanner *sc) {
    char c;
    while (isspace(c = next_char(sc)));
    char *str = (char*)malloc(100);
    int i = 0;
    while (!isspace(c) && c != '\0') {
        str[i++] = c;
        c = next_char(sc);
    }
    str[i] = '\0';
    return str;
}

// Arithmetic
int max(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (m < nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int min(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (m > nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

// Sort
typedef struct {
    int id, num;
} Val;

int compare_num(const void *a, const void *b) {
    Val *val_a = (Val*)a;
    Val *val_b = (Val*)b;
    return val_a->num - val_b->num;
}

// Main function
int main() {
    Scanner *sc = new_scanner();
    int A = next_int(sc);
    int B = next_int(sc);
    int C = next_int(sc);
    int K = next_int(sc);

    int ma = max((int[]){A, B, C}, 3);
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    int answer = pow(ma, K) + rest;
    printf("%d\n", answer);
    free(sc->buffer);
    free(sc);
    return 0;
}
