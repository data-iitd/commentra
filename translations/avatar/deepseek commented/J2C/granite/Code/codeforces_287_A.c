

#include <stdio.h>
#include <string.h>

int main() {
    char str[4][4];
    int i, j, flag = 0;

    for (i = 0; i < 4; i++) {
        scanf("%s", str[i]);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if ((str[i][j] == str[i][j + 1]) && (str[i + 1][j] == str[i][j] || str[i + 1][j + 1] == str[i][j])) {
                flag = 1;
                break;
            } else if ((str[i + 1][j] == str[i + 1][j + 1]) && (str[i][j] == str[i + 1][j] || str[i][j + 1] == str[i + 1][j])) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }

    if (flag == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
