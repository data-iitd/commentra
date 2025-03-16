#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t len;
    size_t pos;
} Scanner;

Scanner* newScanner() {
    Scanner *sc = (Scanner*)malloc(sizeof(Scanner));
    sc->len = 1000;
    sc->buf = (char*)malloc(sc->len);
    sc->pos = 0;
    return sc;
}

char* next(Scanner *sc) {
    pre(sc);
    size_t start = sc->pos;
    while (sc->pos < sc->len && sc->buf[sc->pos] != ' ') {
        sc->pos++;
    }
    char *result = (char*)malloc(sc->pos - start + 1);
    strncpy(result, sc->buf + start, sc->pos - start);
    result[sc->pos - start] = '\0';
    sc->pos++;
    return result;
}

char* nextLine(Scanner *sc) {
    pre(sc);
    size_t start = sc->pos;
    while (sc->pos < sc->len && sc->buf[sc->pos] != '\n') {
        sc->pos++;
    }
    char *result = (char*)malloc(sc->pos - start + 1);
    strncpy(result, sc->buf + start, sc->pos - start);
    result[sc->pos - start] = '\0';
    sc->pos++;
    return result;
}

int nextInt(Scanner *sc) {
    char *token = next(sc);
    int v = atoi(token);
    free(token);
    return v;
}

int* nextIntArray(Scanner *sc, int *size) {
    char *token = next(sc);
    int *result = (int*)malloc(sizeof(int));
    *size = 0;
    for (int i = 0; i < strlen(token); i++) {
        if (token[i] >= '0' && token[i] <= '9') {
            int v = token[i] - '0';
            result = (int*)realloc(result, (*size + 1) * sizeof(int));
            result[*size] = v;
            (*size)++;
            if (token[i + 1] != ' ') {
                free(token);
                panic("Invalid input");
            }
        } else {
            free(token);
            panic("Invalid input");
        }
    }
    free(token);
    return result;
}

map* nextMap(Scanner *sc) {
    char *token = next(sc);
    map *mp = createMap();
    for (int i = 0; i < strlen(token); i++) {
        if (token[i] >= '0' && token[i] <= '9') {
            int k = token[i] - '0';
            token = next(sc);
            if (token[0] != ':') {
                free(token);
                panic("Invalid input");
            }
            bool v = strcmp(next(sc), "true") == 0;
            insertMap(mp, k, v);
            token = next(sc);
            if (token[0] != ' ') {
                free(token);
                panic("Invalid input");
            }
        } else {
            free(token);
            panic("Invalid input");
        }
        if (token == "") {
            break;
        }
    }
    free(token);
    return mp;
}

void pre(Scanner *sc) {
    if (sc->pos >= sc->len) {
        readLine(sc);
        sc->pos = 0;
    }
}

void readLine(Scanner *sc) {
    size_t len = 0;
    ssize_t nread = getline(&sc->buf, &len, stdin);
    if (nread == -1) {
        panic("Invalid input");
    }
    sc->len = nread;
}

void panic(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

