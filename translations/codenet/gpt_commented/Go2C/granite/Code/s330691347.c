
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *X;
} Data;

typedef struct {
    Data *p;
    int len;
} Datas;

void out(int x,...) {
    va_list args;
    va_start(args, x);
    for (int i = 0; i < x; i++) {
        printf("%d ", va_arg(args, int));
    }
    printf("\n");
    va_end(args);
}

int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

char *nextString() {
    int n = 1;
    char *buf = (char *)malloc(sizeof(char) * n);
    char c = getchar();
    int i = 0;
    while (c!= '\n') {
        buf = (char *)realloc(buf, sizeof(char) * ++n);
        buf[i++] = c;
        c = getchar();
    }
    buf[i] = '\0';
    return buf;
}

int compare(const void *a, const void *b) {
    return strcmp(((Data *)a)->X, ((Data *)b)->X);
}

int main() {
    int N = nextInt();
    int L = nextInt();
    Datas s;
    s.len = N;
    s.p = (Data *)malloc(sizeof(Data) * N);
    for (int i = 0; i < N; i++) {
        s.p[i].X = nextString();
    }
    out(N, L, s.p);
    qsort(s.p, s.len, sizeof(Data), compare);
    out(s.p);
    char *ans = (char *)malloc(sizeof(char) * 1000000);
    int len = 0;
    for (int i = 0; i < N; i++) {
        len += strlen(s.p[i].X);
        ans = (char *)realloc(ans, sizeof(char) * len);
        strcat(ans, s.p[i].X);
    }
    printf("%s\n", ans);
    return 0;
}
