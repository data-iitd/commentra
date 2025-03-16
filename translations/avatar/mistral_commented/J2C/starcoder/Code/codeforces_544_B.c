#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, count;
    scanf("%d %d", &n, &count);
    int a = (n + 1) / 2;
    int b = n / 2;
    int max = a * a + b * b;
    if (count > max) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        char *s = (char *) malloc(n + 1);
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && count > 0) {
                s[j] = 'L';
                count--;
            } else {
                s[j] = 'S';
            }
        }
        s[n] = '\0';
        printf("%s\n", s);
        free(s);
    }
    return 0;
}

