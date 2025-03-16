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
    "",
    0
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
    static char word[MAX_LINE_LENGTH];
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

long long max64(long long x, long long y) {
    return x > y ? x : y;
}

int max(int x, int y) {
    return x > y ? x : y;
}

long long min64(long long x, long long y) {
    return x < y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

long long abs64(long long x) {
    return x < 0 ? -x : x;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

char* joinInt64s(long long* a, int len, const char* sep) {
    static char result[MAX_LINE_LENGTH];
    result[0] = '\0';
    for (int i = 0; i < len; i++) {
        char temp[20];
        sprintf(temp, "%lld", a[i]);
        if (i > 0) {
            strcat(result, sep);
        }
        strcat(result, temp);
    }
    return result;
}

char* joinInts(int* a, int len, const char* sep) {
    static char result[MAX_LINE_LENGTH];
    result[0] = '\0';
    for (int i = 0; i < len; i++) {
        char temp[12];
        sprintf(temp, "%d", a[i]);
        if (i > 0) {
            strcat(result, sep);
        }
        strcat(result, temp);
    }
    return result;
}

long long divUp64(long long x, long long y) {
    return (x + y - 1) / y;
}

int divUp(int x, int y) {
    return (x + y - 1) / y;
}

long long gcd64(long long x, long long y) {
    if (x < y) {
        long long temp = x;
        x = y;
        y = temp;
    }
    while (y != 0) {
        long long temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

int gcd(int x, int y) {
    return gcd64(x, y);
}

long long lcm64(long long x, long long y) {
    return x * y / gcd64(x, y);
}

int lcm(int x, int y) {
    return lcm64(x, y);
}

long long pow64(long long x, long long y) {
    return (long long)pow(x, y);
}

int pow(int x, int y) {
    return (int)pow64(x, y);
}

void solve() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[N];
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
