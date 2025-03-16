#include <stdio.h>
#include <string.h>

int main() {
    char str[100], u[100];
    int a, b;

    fgets(str, sizeof(str), stdin);
    fgets(u, sizeof(u), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
    u[strcspn(u, "\n")] = '\0';

    char *token = strtok(str, " ");
    a = atoi(token);
    token = strtok(NULL, " ");
    b = atoi(token);

    if (strcmp(u, str) == 0) {
        printf("%d %d\n", a - 1, b);
    } else {
        printf("%d %d\n", a, b - 1);
    }

    return 0;
}
