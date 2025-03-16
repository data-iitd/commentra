
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *buf;
    int i;
} bufReader;

void reader_init(bufReader *r) {
    r->buf = (char *)malloc(1024 * sizeof(char));
    r->i = 0;
}

void reader_free(bufReader *r) {
    free(r->buf);
}

void reader_readLine(bufReader *r) {
    int c;
    r->i = 0;
    while ((c = getchar())!= '\n') {
        r->buf[r->i++] = c;
    }
    r->buf[r->i] = '\0';
}

char *reader_next(bufReader *r) {
    int c;
    while ((c = getchar()) =='') {
    }
    r->i = 0;
    while (c!='' && c!= '\n') {
        r->buf[r->i++] = c;
        c = getchar();
    }
    r->buf[r->i] = '\0';
    return r->buf;
}

int reader_nextInt(bufReader *r) {
    int x;
    sscanf(reader_next(r), "%d", &x);
    return x;
}

void out(int x) {
    printf("%d\n", x);
}

int max(int x, int y) {
    return x > y? x : y;
}

int main() {
    bufReader r;
    reader_init(&r);
    int N = reader_nextInt(&r);
    int K = reader_nextInt(&r);
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = reader_nextInt(&r);
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
    reader_free(&r);
    return 0;
}
