
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *c = (int *)malloc(n * sizeof(int));
    char s[m + 1];

    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        c[i] = (int)strchr(s, 'S') - (int)strchr(s, 'G');
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] < 0) {
            count = -1;
            break;
        }
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (c[i] == c[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            count++;
        }
    }

    printf("%d\n", count);

    free(c);
    return 0;
}
