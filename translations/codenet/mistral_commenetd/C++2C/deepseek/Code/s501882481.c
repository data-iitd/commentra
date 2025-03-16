#include <stdio.h>
#include <string.h>

#define FOR(i, N) for (int i = 0; i < N; i++)
#define FORIN(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) x, x + (sizeof(x) / sizeof(*x))
#define MOD 1000000007
#define MAX (1 << 29)
#define DEBUG(...) fprintf(stderr, "%d: " __VA_ARGS__)

typedef struct {
    int first;
    int second;
} Pi;

typedef long long ll;
const int INF = 1 << 28;

char* to_string(char* s) {
    return s;
}

char* to_string_pair(Pi p) {
    static char buffer[20];
    sprintf(buffer, "{%d,%d}", p.first, p.second);
    return buffer;
}

char* to_string_vector(char** v, int size) {
    static char buffer[1000];
    buffer[0] = '{';
    for (int i = 0; i < size - 1; ++i) {
        strcat(buffer, v[i]);
        strcat(buffer, ",");
    }
    if (size > 0) {
        strcat(buffer, v[size - 1]);
    }
    strcat(buffer, "}");
    return buffer;
}

void debug() {
    fprintf(stderr, "\n");
}

void debug_multi(int line, char* format, ...) {
    static char buffer[1000];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    fprintf(stderr, "%d: %s\n", line, buffer);
}

void print() {
    printf("\n");
}

void print_multi(char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    print();
}

void get() {}

void get_multi(char* format, ...) {
    va_list args;
    va_start(args, format);
    vscanf(format, args);
    va_end(args);
}

void getv(char** vec, int size) {
    for (int i = 0; i < size; ++i)
        scanf("%s", vec[i]);
}

int main() {
    char S[10];
    scanf("%s", S);

    if (strcmp(S, "Sunny") == 0) {
        print_multi("Cloudy");
    } else if (strcmp(S, "Cloudy") == 0) {
        print_multi("Rainy");
    } else {
        print_multi("Sunny");
    }

    return 0;
}
