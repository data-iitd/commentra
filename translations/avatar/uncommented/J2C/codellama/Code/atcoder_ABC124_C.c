
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000

char *read_line(char *str) {
    char *line = (char *) malloc(MAX_INPUT_SIZE * sizeof(char));
    fgets(line, MAX_INPUT_SIZE, stdin);
    strcpy(str, line);
    free(line);
    return str;
}

int main() {
    char x[MAX_INPUT_SIZE];
    read_line(x);
    int a1 = 0, a2 = 0;
    for (int i = 1; i < strlen(x); i++) {
        if (x[i] == x[i - 1]) {
            if (x[i] == '1') {
                x[i] = '0';
            } else {
                x[i] = '1';
            }
            a1++;
        }
    }
    for (int i = strlen(x) - 1; i > 0; i--) {
        if (x[i] == x[i - 1]) {
            if (x[i - 1] == '1') {
                x[i - 1] = '0';
            } else {
                x[i - 1] = '1';
            }
            a2++;
        }
    }
    printf("%d\n", a1 < a2 ? a1 : a2);
    return 0;
}

