
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
    int size;
    FILE *r;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(sizeof(char) * 1000);
    s->p = 0;
    s->size = 1000;
    s->r = stdin;
    return s;
}

char *next(Scanner *s) {
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

char *nextLine(Scanner *s) {
    s->p = 0;
    while (s->p < s->size) {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p + 1));
    strncpy(result, s->buf, s->p);
    result[s->p] = '\0';
    return result;
}

int nextInt(Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

int nextInt64(Scanner *s) {
    char *str = next(s);
    long long result = atoll(str);
    free(str);
    return result;
}

float nextFloat(Scanner *s) {
    char *str = next(s);
    float result = atof(str);
    free(str);
    return result;
}

int *nextIntArray(Scanner *s) {
    char *str = next(s);
    char *token = strtok(str, " ");
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    while (token!= NULL) {
        result[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(str);
    return result;
}

int64_t *nextInt64Array(Scanner *s) {
    char *str = next(s);
    char *token = strtok(str, " ");
    int64_t *result = (int64_t *)malloc(sizeof(int64_t) * 100);
    int i = 0;
    while (token!= NULL) {
        result[i] = atoll(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(str);
    return result;
}

int main() {
    Scanner *s = newScanner();
    int A = nextInt(s);
    int B = nextInt(s);

    int mx = A + B > A - B? A + B : A - B;
    mx = mx > A * B? mx : A * B;
    printf("%d\n", mx);

    return 0;
}
// END-OF-CODE