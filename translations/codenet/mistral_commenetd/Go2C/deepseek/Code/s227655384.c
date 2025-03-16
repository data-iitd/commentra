#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100000
#define MAX_LINE_LENGTH 100000

char lines[MAX_LINES][MAX_LINE_LENGTH];

void ReadLongLines(int times) {
    int line_count = 0;
    char buffer[MAX_LINE_LENGTH];
    int buffer_size = 0;

    while (line_count < times && fgets(buffer, sizeof(buffer), stdin) != NULL) {
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }
        strcpy(lines[line_count], buffer);
        line_count++;
    }
}

void PrintList(int *list, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%d", list[i]);
        } else {
            printf(" %d", list[i]);
        }
    }
    printf("\n");
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    ReadLongLines(4);

    int m[200000] = {0};
    char *token;

    token = strtok(lines[1], " ");
    while (token != NULL) {
        int n = atoi(token);
        m[n] = 1;
        token = strtok(NULL, " ");
    }

    token = strtok(lines[3], " ");
    while (token != NULL) {
        int n = atoi(token);
        if (m[n] == 0) {
            m[n] = 1;
        }
        token = strtok(NULL, " ");
    }

    int result[200000];
    int result_size = 0;
    for (int i = 0; i < 200000; i++) {
        if (m[i] == 1) {
            result[result_size++] = i;
        }
    }

    qsort(result, result_size, sizeof(int), compare);

    for (int i = 0; i < result_size; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
