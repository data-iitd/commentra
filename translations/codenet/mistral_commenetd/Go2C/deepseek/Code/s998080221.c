#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char buf[MAX_LINE_LENGTH];
    size_t pos;
} bufReader;

bufReader reader = {
    .pos = 0,
};

void readLine() {
    if (reader.pos < strlen(reader.buf)) {
        return;
    }
    reader.buf[0] = '\0';
    reader.pos = 0;
    fgets(reader.buf, MAX_LINE_LENGTH, stdin);
    if (reader.buf[0] == '\n') {
        fgets(reader.buf, MAX_LINE_LENGTH, stdin);
    }
}

char* next() {
    readLine();
    static char token[MAX_LINE_LENGTH];
    size_t from = reader.pos;
    while (reader.pos < strlen(reader.buf) && reader.buf[reader.pos] != ' ') {
        reader.pos++;
    }
    strncpy(token, reader.buf + from, reader.pos - from);
    token[reader.pos - from] = '\0';
    reader.pos++;
    return token;
}

int nextInt() {
    char* str = next();
    int num = atoi(str);
    return num;
}

char* nextLine() {
    readLine();
    char* line = (char*)malloc(strlen(reader.buf) + 1);
    strcpy(line, reader.buf);
    reader.pos = 0;
    return line;
}

void out(int a, ...) {
    va_list args;
    va_start(args, a);
    printf("%d", a);
    while ((a = va_arg(args, int)) != 0) {
        printf(" %d", a);
    }
    printf("\n");
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
        char temp[12];
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
    return x * (y / gcd(x, y));
}

int pow(int x, int y) {
    return (int)pow(x, y);
}

void solve() {
    int N = nextInt();
    int K = nextInt();
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = nextInt();
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
    out(maxCnt);
}

int main() {
    solve();
    return 0;
}
