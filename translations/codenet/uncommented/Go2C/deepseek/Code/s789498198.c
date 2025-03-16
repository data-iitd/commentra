#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char **buf;
    int cur;
    FILE *r;
} scanner;

void readln(scanner *s) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, s->r)) != -1) {
        char *token = strtok(line, " ");
        int count = 0;
        while (token != NULL) {
            s->buf[count++] = token;
            token = strtok(NULL, " ");
        }
        s->cur = 0;
    }
    free(line);
}

int isFull(scanner *s) {
    return s->cur == count;
}

void resetCur(scanner *s) {
    s->cur = 0;
}

char* next(scanner *s) {
    if (s->cur == 0) {
        readln(s);
    }
    char* res = s->buf[s->cur];
    s->cur++;
    if (isFull(s)) {
        resetCur(s);
    }
    return res;
}

int* nextInts(scanner *s) {
    readln(s);
    int *res = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        res[i] = atoi(s->buf[i]);
    }
    resetCur(s);
    return res;
}

int nextInt(scanner *s) {
    if (s->cur == 0) {
        readln(s);
    }
    int res = atoi(s->buf[s->cur]);
    s->cur++;
    if (isFull(s)) {
        resetCur(s);
    }
    return res;
}

float nextFloat(scanner *s) {
    if (s->cur == 0) {
        readln(s);
    }
    float res = atof(s->buf[s->cur]);
    s->cur++;
    if (isFull(s)) {
        resetCur(s);
    }
    return res;
}

float* nextFloats(scanner *s) {
    readln(s);
    float *res = (float*)malloc(count * sizeof(float));
    for (int i = 0; i < count; i++) {
        res[i] = atof(s->buf[i]);
    }
    resetCur(s);
    return res;
}

int digits(int x) {
    char str[20];
    sprintf(str, "%d", x);
    return strlen(str);
}

int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

void varDump(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        int *p = va_arg(args, int*);
        printf("%d\n", *p);
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
    int size;
    int capacity;
} Queue;

void push(Queue *q, Pair p) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->v = (Pair*)realloc(q->v, q->capacity * sizeof(Pair));
    }
    q->v[q->size++] = p;
}

Pair pop(Queue *q) {
    Pair r = q->v[0];
    for (int i = 1; i < q->size; i++) {
        q->v[i - 1] = q->v[i];
    }
    q->size--;
    return r;
}

Pair front(Queue q) {
    return q.v[0];
}

int empty(Queue q) {
    return q.size == 0;
}

int main() {
    scanner s = {NULL, 0, stdin};
    s.buf = (char**)malloc(100 * sizeof(char*));

    int A = nextInt(&s);
    int B = nextInt(&s);

    if ((A + B) % 2 == 0) {
        printf("%d\n", (A + B) / 2);
    } else {
        printf("IMPOSSIBLE\n");
    }

    free(s.buf);
    return 0;
}

