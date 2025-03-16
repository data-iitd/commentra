
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    bool c[m];
    for (int i = 0; i < m; i++) {
        c[i] = false;
    }

    char s[n];
    for (int i = 0; i < m; i++) {
        scanf("%s", s);

        int index_S = -1;
        int index_G = -1;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'S') {
                index_S = j;
            } else if (s[j] == 'G') {
                index_G = j;
            }
        }

        int difference = index_S - index_G;
        if (difference < 0) {
            c[i] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        if (!c[i]) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
