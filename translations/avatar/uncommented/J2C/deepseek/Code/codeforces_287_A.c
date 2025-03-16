#include <stdio.h>
#include <string.h>

int main() {
    char str[4][10];
    int i = -1, u = -1, yes = 0;

    while (i != 3) {
        i++;
        scanf("%s", str[i]);
    }

    while (u != 2) {
        u++;
        i = -1;
        while (i != 2) {
            i++;
            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) ||
                (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = 1;
                printf("YES\n");
                break;
            }
        }
        if (yes == 1) {
            break;
        }
    }

    if (yes == 0) {
        printf("NO\n");
    }

    return 0;
}
