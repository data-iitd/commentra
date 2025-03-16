#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long a;
    char b[100];
    char bStr[100];
    int bInt;
    long result;

    scanf("%ld", &a);
    scanf("%s", b);

    int length = strlen(b);
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (b[i] != '.') {
            bStr[j++] = b[i];
        }
    }
    bStr[j] = '\0';

    bInt = atoi(bStr);

    result = (a * bInt) / 100;

    printf("%ld\n", result);

    return 0;
}

