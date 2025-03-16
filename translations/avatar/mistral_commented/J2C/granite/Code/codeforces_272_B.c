

#include <stdio.h>
#include <stdlib.h>

// Initialize FastReader for reading input
typedef struct {
    char buf[200000], *p1, *p2;
} FastReader;

void initReader(FastReader *fr) {
    fr->p1 = fr->buf;
    fr->p2 = fr->buf;
    fr->buf[0] = getchar();
}

char readChar(FastReader *fr) {
    if (fr->p1 == fr->p2) {
        fr->p1 = fr->buf;
        fr->p2 = fr->buf + fread(fr->buf, 1, 200000, stdin);
        fr->p2[0] = 0;
    }
    return fr->p1[0]++;
}

int readInt(FastReader *fr) {
    int x = 0, f = 1;
    char ch = readChar(fr);
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = readChar(fr);
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = readChar(fr);
    }
    return x * f;
}

long long readLong(FastReader *fr) {
    long long x = 0, f = 1;
    char ch = readChar(fr);
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = readChar(fr);
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = readChar(fr);
    }
    return x * f;
}

double readDouble(FastReader *fr) {
    long long x = readLong(fr);
    char ch = readChar(fr);
    while (ch < '0' || ch > '9') {
        ch = readChar(fr);
    }
    double tmp = 1;
    while (ch >= '0' && ch <= '9') {
        tmp = tmp / 10;
        x = x + (ch - '0') * tmp;
        ch = readChar(fr);
    }
    return (double) x;
}

char readChar(FastReader *fr) {
    if (fr->p1 == fr->p2) {
        fr->p1 = fr->buf;
        fr->p2 = fr->buf + fread(fr->buf, 1, 200000, stdin);
        fr->p2[0] = 0;
    }
    return fr->p1[0]++;
}

char readString(FastReader *fr, char *s) {
    int len = 0;
    char ch = readChar(fr);
    while (ch =='' || ch == '\n') {
        ch = readChar(fr);
    }
    while (ch!='' && ch!= '\n') {
        s[len++] = ch;
        ch = readChar(fr);
    }
    s[len] = '\0';
    return len;
}

int main() {
    FastReader fr;
    initReader(&fr);

    int n = readInt(&fr);

    int a[33] = {0};

    for (int i = 0; i < n; i++) {
        int num = readInt(&fr);
        int index = rec(num);
        a[index]++;
    }

    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }
    printf("%lld\n", (long long) answer);

    return 0;
}

int rec(long x) {
    int answer = 0;

    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k))!= 0) {
            answer++;
        }
    }

    return answer;
}

