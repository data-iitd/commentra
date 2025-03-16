
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long A;
    long B;
    long K;
    long x;
    long y;
} Main;

void calc(Main *ins) {
    ins->x = ins->A;
    ins->y = ins->B;

    ins->x = ins->A - ins->K;

    if (ins->x < 0) {
        ins->y = ins->B + ins->x;
        ins->x = 0;
    }

    if (ins->y < 0) {
        ins->y = 0;
    }
}

void showResult(Main *ins) {
    printf("%ld %ld\n", ins->x, ins->y);
}

int main() {
    Main ins;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1) {
        return 1;
    }

    char *token = strtok(line, " ");
    ins.A = strtol(token, NULL, 10);

    token = strtok(NULL, " ");
    ins.B = strtol(token, NULL, 10);

    token = strtok(NULL, " ");
    ins.K = strtol(token, NULL, 10);

    calc(&ins);
    showResult(&ins);

    free(line);

    return 0;
}

