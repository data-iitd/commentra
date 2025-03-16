
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char **l = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        l[i] = (char *)malloc(101 * sizeof(char));
        scanf("%s", l[i]);
    }
    int *s = (int *)malloc(101 * sizeof(int));
    memset(s, 0, 101 * sizeof(int));
    char *f = "Yes";
    for (int i = 0; i < n; i++) {
        s[l[i][0]]++;
        if (s[l[i][0]] >= 2) {
            f = "No";
        }
        if (i > 0 && l[i - 1][strlen(l[i - 1]) - 1]!= l[i][0]) {
            f = "No";
        }
    }
    printf("%s\n", f);
    for (int i = 0; i < n; i++) {
        free(l[i]);
    }
    free(l);
    free(s);
    return 0;
}
