

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    int p;
    int size;
    FILE *fp;
} FastScanner;

FastScanner *NewFastScanner(FILE *fp) {
    FastScanner *s = (FastScanner *)malloc(sizeof(FastScanner));
    s->buf = (char *)malloc(sizeof(char) * 1024);
    s->p = 0;
    s->size = 1024;
    s->fp = fp;
    return s;
}

void FreeFastScanner(FastScanner *s) {
    free(s->buf);
    free(s);
}

char *Next(FastScanner *s) {
    s->p = 0;
    while (s->p < s->size && s->buf[s->p]!='') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p + 1));
    strncpy(result, s->buf, s->p);
    result[s->p] = '\0';
    s->p++;
    return result;
}

char *NextLine(FastScanner *s) {
    s->p = 0;
    while (s->p < s->size && s->buf[s->p]!= '\n') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p + 1));
    strncpy(result, s->buf, s->p);
    result[s->p] = '\0';
    s->p++;
    return result;
}

int NextInt(FastScanner *s) {
    char *str = Next(s);
    int result = atoi(str);
    free(str);
    return result;
}

int NextInt64(FastScanner *s) {
    char *str = Next(s);
    int64_t result = atoll(str);
    free(str);
    return result;
}

void pre(FastScanner *s) {
    if (s->p >= s->size) {
        fread(s->buf, sizeof(char), s->size, s->fp);
        s->p = 0;
    }
}

void readLine(FastScanner *s) {
    s->p = 0;
    while (fread(s->buf + s->p, sizeof(char), 1, s->fp) && s->buf[s->p]!= '\n') {
        s->p++;
    }
    s->buf[s->p] = '\0';
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    FastScanner *s = NewFastScanner(fp);
    int A = NextInt(s);
    int B = NextInt(s);
    int C = NextInt(s);
    if (B - A == C - B) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    FreeFastScanner(s);
    fclose(fp);
    return 0;
}

