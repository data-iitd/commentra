#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 4
#define MAX_LINE_LENGTH 256

char** readLongLines(int times, int* lineCount) {
    char** result = (char**)malloc(times * sizeof(char*));
    for (int i = 0; i < times; i++) {
        result[i] = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    char buffer[MAX_LINE_LENGTH];
    int readBytes = 0;
    int lineIndex = 0;

    for (int i = 0; i < times; i++) {
        while (fgets(buffer, MAX_LINE_LENGTH, stdin) != NULL) {
            readBytes += strlen(buffer);
            strcpy(result[lineIndex], buffer);
            lineIndex++;
            if (lineIndex == times) {
                break;
            }
        }
    }

    *lineCount = lineIndex;
    return result;
}

void printList(int* list, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%d", list[i]);
        } else {
            printf(" %d", list[i]);
        }
    }
    printf("\n");
}

int main() {
    int lineCount;
    char** lines = readLongLines(MAX_LINES, &lineCount);

    int m[200000] = {0};
    char* a[200000];
    int aCount = 0;

    char* token = strtok(lines[1], " ");
    while (token != NULL) {
        a[aCount++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < aCount; i++) {
        int n = atoi(a[i]);
        m[n] = 1;
    }

    char* b[200000];
    int bCount = 0;

    token = strtok(lines[3], " ");
    while (token != NULL) {
        b[bCount++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < bCount; i++) {
        int n = atoi(b[i]);
        if (m[n] == 1) {
            m[n] = 0;
        } else {
            m[n] = 1;
        }
    }

    int result[200000];
    int resultCount = 0;

    for (int i = 0; i < 200000; i++) {
        if (m[i] == 1) {
            result[resultCount++] = i;
        }
    }

    for (int i = 0; i < resultCount; i++) {
        printf("%d\n", result[i]);
    }

    for (int i = 0; i < MAX_LINES; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
