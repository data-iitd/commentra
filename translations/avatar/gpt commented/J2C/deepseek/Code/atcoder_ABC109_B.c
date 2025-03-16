#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char **strings = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        strings[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", strings[i]);
    }

    int ans = 1;
    char *past[N];
    for (int i = 0; i < N; i++) {
        past[i] = (char *)malloc(100 * sizeof(char));
    }

    char *next = (char *)malloc(1 * sizeof(char));
    next[0] = '\0';

    for (int i = 0; i < N; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(past[j], strings[i]) == 0) {
                ans = 0;
                found = 1;
                break;
            }
        }
        if (found) break;

        strcpy(past[i], strings[i]);

        if (i != 0) {
            if (next[0] != strings[i][0]) {
                ans = 0;
                break;
            }
        }

        next[0] = strings[i][strlen(strings[i]) - 1];
    }

    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    for (int i = 0; i < N; i++) {
        free(strings[i]);
        free(past[i]);
    }
    free(strings);
    free(past);
    free(next);

    return 0;
}
