#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    char *list[3];
    int x, a, y;
    char h[3] = "NO";

    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        list[i++] = token;
        token = strtok(NULL, " ");
    }

    x = atoi(list[0]);
    a = atoi(list[1]);
    y = atoi(list[2]);

    if ((x == 5 || x == 7) || (a == 5 || a == 7) || (y == 5 || y == 7)) {
        if (x + y + a == 17) {
            strcpy(h, "YES");
        }
    }

    printf("%s\n", h);
    return 0;
}
