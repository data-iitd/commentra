#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char input[1000];
    scanf(" %[^\n]", input);

    char *m[1000];
    char *token = strtok(input, " ");
    int index = 0;

    while (token != NULL) {
        m[index++] = token;
        token = strtok(NULL, " ");
    }

    int possible = 1;

    for (int i = 0; i < index; i++) {
        int count = 0;
        for (int j = 0; j < index; j++) {
            if (strcmp(m[i], m[j]) == 0) {
                count++;
            }
        }
        if (count >= n / 2 + 1) {
            possible = 0;
            break;
        }
    }

    if (possible) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
