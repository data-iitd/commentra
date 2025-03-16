#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[n][n];
    char str[n][n+1];

    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[i][j];
        }
    }

    char a = arr[0][0];
    char b = arr[0][1];

    if (a == b) {
        printf("NO\n");
    } else {
        int res = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == j || i + j == n - 1)) {
                    if (arr[i][j] != a) {
                        res = 0;
                        break;
                    }
                } else {
                    if (arr[i][j] != b) {
                        res = 0;
                        break;
                    }
                }
            }
            if (!res) break;
        }

        if (res) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
