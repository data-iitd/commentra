#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char input[100];
    scanf("%s", input);

    int sa = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '-') {
            sa++;
        }
    }

    sa = n - sa < sa ? n - sa : sa;

    char ss[m][2];
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        b -= a;

        if (b % 2 && b <= sa * 2) {
            strcpy(ss[i], "1\n");
        } else {
            strcpy(ss[i], "0\n");
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%s", ss[i]);
    }

    return 0;
}
