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

template <class S, class T>
char* to_string(Pi p) {
    static char buffer[50];
    sprintf(buffer, "{%d,%d}", p.first, p.second);
    return buffer;
}

template <class T>
char* to_string(T* v, int size) {
    static char buffer[1000];
    buffer[0] = '{';
    for (int i = 0; i < size - 1; ++i) {
        strcat(buffer, to_string(v[i]));
        strcat(buffer, ",");
    }
    if (size > 0) {
        strcat(buffer, to_string(v[size - 1]));
    }
    strcat(buffer, "}");
    return buffer;
}

void debug() {
    fprintf(stderr, "\n");
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
    fprintf(stderr, "%s ", to_string(head));
    debug(tail...);
}

void print() {
    printf("\n");
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
    printf("%s", to_string(head));
    print(tail...);
}

void get() {}

template <class Head, class... Tail>
void get(Head* head, Tail*... tail) {
    scanf("%d", head);
    get(tail...);
}

template <class T>
void getv(T* vec, int size) {
    for (int i = 0; i < size; ++i)
        scanf("%d", &vec[i]);
}

int main() {
    char S[100];
    scanf("%s", S);

    if (strcmp(S, "Sunny") == 0) {
        print("Cloudy");
    } else if (strcmp(S, "Cloudy") == 0) {
        print("Rainy");
    } else {
        print("Sunny");
    }

    return 0;
}
