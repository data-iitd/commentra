#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000000

char line[MAX_LINE_LENGTH];
int pos = 0;

char nextChar() {
    return line[pos++];
}

int nextInt() {
    int num = 0;
    char ch;
    while ((ch = nextChar()) != ' ' && ch != '\n') {
        num = num * 10 + (ch - '0');
    }
    return num;
}

float nextFloat() {
    float num = 0.0;
    int decimal = 0;
    int sign = 1;
    char ch;
    while ((ch = nextChar()) == ' ') {}
    if (ch == '-') {
        sign = -1;
        ch = nextChar();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + (ch - '0');
        ch = nextChar();
    }
    if (ch == '.') {
        ch = nextChar();
        while (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
            decimal++;
            ch = nextChar();
        }
    }
    for (int i = 0; i < decimal; i++) {
        num /= 10.0;
    }
    return sign * num;
}

char* next() {
    int len = 0;
    char ch;
    while ((ch = nextChar()) == ' ') {}
    do {
        line[len++] = ch;
        ch = nextChar();
    } while (ch != ' ' && ch != '\n');
    line[len] = '\0';
    return line;
}

int* nextInts(int n) {
    int* slice = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        slice[i] = nextInt();
    }
    return slice;
}

float* nextFloat64s(int n) {
    float* slice = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        slice[i] = nextFloat();
    }
    return slice;
}

char* nextMega() {
    int len = 0;
    char ch;
    while ((ch = getchar()) != EOF) {
        line[len++] = ch;
    }
    line[len] = '\0';
    return line;
}

void putf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
}

void puts(const char* a) {
    fprintf(stdout, "%s\n", a);
}

int main() {
    // Initialize the buffer for input
    fgets(line, MAX_LINE_LENGTH, stdin);
    pos = 0;

    int n = nextInt();
    int* a = nextInts(n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1;
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }
        ans++;
        i = r;
    }
    puts(strdup(strconv.Itoa(ans).c_str()));
    fflush(stdout);
    return 0;
}
