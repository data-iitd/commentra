
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* s(void) {
    char* input = malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    int* a = malloc(100 * sizeof(int));
    char* token = strtok(input, " ");
    int i = 0;
    while (token!= NULL) {
        a[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    qsort(a, i, sizeof(int));
    for (int j = 1; j < i; j++) {
        if (a[j]!= a[j - 1] && a[j] < a[j - 1] * 2) {
            return "YES";
        }
    }
    return "NO";
}

int main(void) {
    char* result = s();
    printf("%s\n", result);
    free(result);
    return 0;
}

