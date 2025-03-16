#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    size_t line_index;
    char *token;
} FastReader;

FastReader* createFastReader(FILE *file) {
    FastReader *fr = (FastReader *)malloc(sizeof(FastReader));
    fr->file = file;
    fr->line_index = 0;
    return fr;
}

char* next(FastReader *fr) {
    if (fr->token != NULL && fr->token[0] != '\0') {
        free(fr->token);
    }
    fr->token = NULL;
    while (fr->token == NULL || fr->token[0] == '\0') {
        if (fgets(fr->line, MAX_LINE_LENGTH, fr->file) != NULL) {
            fr->line_index = 0;
            fr->token = strtok(fr->line, " \t\n");
        } else {
            return NULL;
        }
    }
    return fr->token;
}

int nextInt(FastReader *fr) {
    return atoi(next(fr));
}

long nextLong(FastReader *fr) {
    return atol(next(fr));
}

double nextDouble(FastReader *fr) {
    return atof(next(fr));
}

void solve(FastReader *fr) {
    int t = nextInt(fr);
    int arr[t];
    for (int i = 0; i < t; i++) {
        arr[i] = nextInt(fr);
    }
    int prevWinner = 0;
    for (int i = 0; i < t; i++) {
        if (arr[i] == 1) {
            if (prevWinner == 0) {
                prevWinner = 2;
            }
        }
        if (prevWinner == 2 || prevWinner == 0) {
            if ((arr[i] - 1) % 2 == 0) {
                printf("2\n");
                prevWinner = 2;
            } else {
                printf("1\n");
                prevWinner = 1;
            }
        } else {
            if ((arr[i] - 1) % 2 == 0) {
                printf("1\n");
                prevWinner = 1;
            } else {
                printf("2\n");
                prevWinner = 2;
            }
        }
    }
}

int main() {
    FastReader *fr = createFastReader(stdin);
    int t = 1;
    while (t--) {
        solve(fr);
    }
    free(fr);
    return 0;
}
