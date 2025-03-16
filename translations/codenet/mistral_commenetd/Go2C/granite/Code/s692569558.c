

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ds[100];
    int dn[100];
    int sum = 0;

    fgets(ds, 100, stdin);
    fgets(ds, 100, stdin);

    char *token = strtok(ds, " ");
    int i = 0;
    while (token!= NULL) {
        dn[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    for (int i = 0; i < i - 1; i++) {
        for (int j = i + 1; j < i; j++) {
            sum += dn[i] * dn[j];
        }
    }

    printf("%d\n", sum);

    return 0;
}

