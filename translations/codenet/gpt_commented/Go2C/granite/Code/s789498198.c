
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **buf;
    int cur;
    int r;
} Scanner;

void initScanner(Scanner *s) {
    s->buf = malloc(sizeof(char *) * 100);
    s->cur = 0;
    s->r = 0;
}

void readln(Scanner *s) {
    char *rbuf = malloc(sizeof(char) * 1000);
    int i = 0;
    while (1) {
        char line[1000];
        int prefix;
        fgets(line, 1000, stdin);
        strcat(rbuf, line);
        sscanf(line, "%n", &prefix);
        if (prefix == 0) {
            break;
        }
    }
    char *token = strtok(rbuf, " ");
    for (i = 0; token!= NULL; i++) {
        s->buf[i] = token;
        token = strtok(NULL, " ");
    }
    s->cur = 0;
    s->r = i;
}

char *next(Scanner *s) {
    if (s->cur == 0) {
        readln(s);
    }
    char *res = s->buf[s->cur];
    s->cur++;
    if (s->cur == s->r) {
        s->cur = 0;
        s->r = 0;
    }
    return res;
}

char **nexts(Scanner *s) {
    readln(s);
    s->cur = 0;
    return s->buf;
}

int nextInt(Scanner *s) {
    if (s->cur == 0) {
        readln(s);
    }
    int res;
    sscanf(s->buf[s->cur], "%d", &res);
    s->cur++;
    if (s->cur == s->r) {
        s->cur = 0;
        s->r = 0;
    }
    return res;
}

int *nextInts(Scanner *s) {
    int i;
    int *res = malloc(sizeof(int) * 100);
    char **buf = nexts(s);
    for (i = 0; buf[i]!= NULL; i++) {
        sscanf(buf[i], "%d", &res[i]);
    }
    s->cur = 0;
    s->r = 0;
    return res;
}

float nextFloat(Scanner *s) {
    if (s->cur == 0) {
        readln(s);
    }
    float res;
    sscanf(s->buf[s->cur], "%f", &res);
    s->cur++;
    if (s->cur == s->r) {
        s->cur = 0;
        s->r = 0;
    }
    return res;
}

float *nextFloats(Scanner *s) {
    int i;
    float *res = malloc(sizeof(float) * 100);
    char **buf = nexts(s);
    for (i = 0; buf[i]!= NULL; i++) {
        sscanf(buf[i], "%f", &res[i]);
    }
    s->cur = 0;
    s->r = 0;
    return res;
}

int digits(int x) {
    return (int)log10((double)x) + 1;
}

int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int max(int x, int y) {
    return x > y? x : y;
}

int min(int x, int y) {
    return x < y? x : y;
}

int abs(int x) {
    return x < 0? -x : x;
}

void varDump(int value,...) {
    va_list args;
    va_start(args, value);
    for (int i = 0; i < value; i++) {
        printf("%d\n", va_arg(args, int));
    }
    va_end(args);
}

void yes() {
    printf("Yes\n");
}

void no() {
    printf("No\n");
}

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    Pair *v;
} Queue;

void initQueue(Queue *q) {
    q->v = malloc(sizeof(Pair) * 100);
}

void push(Queue *q, Pair v) {
    q->v[q->size++] = v;
}

Pair pop(Queue *q) {
    Pair r = q->v[--q->size];
    return r;
}

Pair front(Queue *q) {
    return q->v[q->front];
}

int empty(Queue *q) {
    return q->size == 0;
}

