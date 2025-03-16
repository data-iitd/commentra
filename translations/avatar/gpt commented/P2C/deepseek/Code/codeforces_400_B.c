#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int differences[1000] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        char s[1001];
        scanf("%s", s);

        int index_S = -1, index_G = -1;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'S') {
                index_S = j;
            } else if (s[j] == 'G') {
                index_G = j;
            }
        }

        if (index_S != -1 && index_G != -1) {
            int difference = index_S - index_G;
            int is_new = 1;
            for (int k = 0; k < count; k++) {
                if (differences[k] == difference) {
                    is_new = 0;
                    break;
                }
            }
            if (is_new) {
                differences[count++] = difference;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        if (differences[i] < 0) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", count);
    return 0;
}
