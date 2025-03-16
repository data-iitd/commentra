
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
    while (s->buf[s->p]!='' && s->p < s->size) {
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
    while (s->buf[s->p]!= '\n' && s->p < s->size) {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int result = atoi(token);
    free(token);
    return result;
}

int64_t nextInt64(Scanner *s) {
    char *token = next(s);
    int64_t result = atoll(token);
    free(token);
    return result;
}

float nextFloat(Scanner *s) {
    char *token = next(s);
    float result = atof(token);
    free(token);
    return result;
}

int *nextIntArray(Scanner *s) {
    char *token = next(s);
    char *saveptr;
    char *token2 = NULL;
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    char *ptr = token;
    while ((token2 = strtok_r(ptr, " ", &saveptr))!= NULL) {
        result[i] = atoi(token2);
        i++;
        ptr = NULL;
    }
    free(token);
    return result;
}

int64_t *nextInt64Array(Scanner *s) {
    char *token = next(s);
    char *saveptr;
    char *token2 = NULL;
    int64_t *result = (int64_t *)malloc(sizeof(int64_t) * 100);
    int i = 0;
    char *ptr = token;
    while ((token2 = strtok_r(ptr, " ", &saveptr))!= NULL) {
        result[i] = atoll(token2);
        i++;
        ptr = NULL;
    }
    free(token);
    return result;
}

int main() {
    Scanner *s = newScanner();
    int H = nextInt(s);
    int W = nextInt(s);
    int N = nextInt(s);
    int A = H > W? H : W;
    int result = (N + A - 1) / A;
    printf("%d\n", result);
    freeScanner(s);
    return 0;
}

// END-OF-CODE