
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char** s = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        s[i] = (char*)malloc(10 * sizeof(char));
        scanf("%s", s[i]);
    }

    int* count = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(s[i], s[j]) == 0) {
                count[i]++;
            }
        }
    }

    int max_count = 0;
    int max_index = -1;
    for (int i = 0; i < n; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_index = i;
        }
    }

    char* result = (char*)malloc(10 * sizeof(char));
    strcpy(result, s[max_index]);

    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    free(count);

    printf("%s\n", result);

    return 0;
}

Translate the above C code to Java and end with comment "