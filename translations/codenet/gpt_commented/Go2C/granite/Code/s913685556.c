
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
    int size;
    FILE *fp;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(sizeof(char) * 1000);
    s->p = 0;
    s->size = 1000;
    s->fp = stdin;
    return s;
}

void freeScanner(Scanner *s) {
    free(s->buf);
    free(s);
}

char *next(Scanner *s) {
    int start = s->p;
    while (s->p < s->size && s->buf[s->p]!='') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    int start = s->p;
    while (s->p < s->size) {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int result = atoi(token);
    free(token);
    return result;
}

long long nextLong(Scanner *s) {
    char *token = next(s);
    long long result = atoll(token);
    free(token);
    return result;
}

double nextDouble(Scanner *s) {
    char *token = next(s);
    double result = atof(token);
    free(token);
    return result;
}

int *nextIntArray(Scanner *s) {
    char *token = next(s);
    char *saveptr;
    char *token2 = NULL;
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    while ((token2 = strtok_r(token, " ", &saveptr))!= NULL) {
        result[i] = atoi(token2);
        i++;
        token = NULL;
    }
    free(token);
    return result;
}

long long *nextLongArray(Scanner *s) {
    char *token = next(s);
    char *saveptr;
    char *token2 = NULL;
    long long *result = (long long *)malloc(sizeof(long long) * 100);
    int i = 0;
    while ((token2 = strtok_r(token, " ", &saveptr))!= NULL) {
        result[i] = atoll(token2);
        i++;
        token = NULL;
    }
    free(token);
    return result;
}

int main() {
    Scanner *s = newScanner();
    int A = nextInt(s);
    int B = nextInt(s);
    int mx = A + B > A - B? A + B : A - B;
    mx = mx > A * B? mx : A * B;
    printf("%d\n", mx);
    freeScanner(s);
    return 0;
}

// END-OF-CODE