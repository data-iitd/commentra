
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, b, tap = 0, consent = 1;
    char *line = NULL;
    size_t len = 0;
    int *arr = NULL;
    int arr_size = 0;

    if (getline(&line, &len, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, " ");
    while (token!= NULL) {
        arr_size++;
        token = strtok(NULL, " ");
    }

    arr = (int *)malloc(arr_size * sizeof(int));
    if (arr == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " ");
    for (int i = 0; i < arr_size; i++) {
        arr[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    a = arr[0];
    b = arr[1];

    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }

    printf("%d\n", tap);

    free(arr);
    free(line);

    return 0;
}
