#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char buf[MAX_LINE_LENGTH];
    size_t i;
} bufReader;

bufReader reader = {
    .i = 0
};

void readLine() {
    if (reader.i < strlen(reader.buf)) {
        return;
    }
    reader.i = 0;
    fgets(reader.buf, MAX_LINE_LENGTH, stdin);
}

char* next() {
    readLine();
    static char word[100];
    size_t from = reader.i;
    while (reader.buf[reader.i] != ' ' && reader.buf[reader.i] != '\0' && reader.buf[reader.i] != '\n') {
        reader.i++;
    }
    strncpy(word, reader.buf + from, reader.i - from);
    word[reader.i - from] = '\0';
    reader.i++;
    return word;
}

char* nextLine() {
    readLine();
    return strdup(reader.buf);
}

void out(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

char* joinInts(int* a, int len, const char* sep) {
    static char result[1024];
    result[0] = '\0';
    for (int i = 0; i < len; i++) {
        char temp[20];
        sprintf(temp, "%d", a[i]);
        if (i > 0) {
            strcat(result, sep);
        }
        strcat(result, temp);
    }
    return result;
}

int divUp(int x, int y) {
    return (x + y - 1) / y;
}

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int pow(int x, int y) {
    return (int)powf((float)x, (float)y);
}

void solve() {
    int N, M;
    int A[100000];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        int profit = max(0, maxA - A[i]);
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        maxA = max(maxA, A[i]);
    }
    out("%d\n", maxCnt);
}

int main() {
    solve();
    return 0;
}
