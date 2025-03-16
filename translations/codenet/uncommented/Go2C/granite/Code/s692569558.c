
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    fgets(buf, sizeof(buf), stdin);
    char *ds = buf;

    char *d = strtok(ds, " ");
    int dn[100];
    int i = 0;
    while (d!= NULL) {
        dn[i++] = atoi(d);
        d = strtok(NULL, " ");
    }

    int sum = 0;
    for (int i = 0; i < i; i++) {
        for (int j = i + 1; j < i; j++) {
            sum += dn[i] * dn[j];
        }
    }

    printf("%d\n", sum);
    return 0;
}
