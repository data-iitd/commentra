
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n, i, j;
    char *c;
    char p = 'a';

    scanf("%d", &n);
    c = (char *) malloc(n * sizeof(char));

    for (i = 0; i < 4; i++) {
        for (j = i; j < n; j += 4) {
            c[j] = p;
            p++;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%c", c[i]);
    }

    return EXIT_SUCCESS;
}

