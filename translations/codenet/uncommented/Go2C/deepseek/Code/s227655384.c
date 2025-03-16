#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char** readLongLines(int times, int* readBytes) {
    char** result = (char**)malloc(times * sizeof(char*));
    for (int i = 0; i < times; i++) {
        result[i] = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    char buffer[MAX_LINE_LENGTH];
    int totalBytes = 0;
    for (int i = 0; i < times; i++) {
        int j = 0;
        while (1) {
            char ch = getchar();
            if (ch == '\n') {
                buffer[j] = '\0';
                strcpy(result[i], buffer);
                totalBytes += j + 1;
                break;
            } else {
                buffer[j] = ch;
                j++;
                if (j >= MAX_LINE_LENGTH - 1) {
                    buffer[j] = '\0';
                    strcpy(result[i], buffer);
                    totalBytes += j + 1;
                    break;
                }
            }
        }
    }
    *readBytes = totalBytes;
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

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int readBytes;
    char** lines = readLongLines(4, &readBytes);
    char* a_str = lines[1];
    char* b_str = lines[3];

    int a[200000];
    int b[200000];
    int m[200000] = {0};
    int result[200000];

    int a_count = 0, b_count = 0;
    char* token = strtok(a_str, " ");
    while (token != NULL) {
        a[a_count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    token = strtok(b_str, " ");
    while (token != NULL) {
        b[b_count++] = atoi(token);
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < a_count; i++) {
        m[a[i]] = 1;
    }

    for (int i = 0; i < b_count; i++) {
        if (m[b[i]] == 1) {
            m[b[i]] = 0;
        } else {
            m[b[i]] = 1;
        }
    }

    int result_count = 0;
    for (int i = 0; i < 200000; i++) {
        if (m[i] == 1) {
            result[result_count++] = i;
        }
    }

    qsort(result, result_count, sizeof(int), compare);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    for (int i = 0; i < 4; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
