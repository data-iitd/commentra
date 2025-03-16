#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long a;
    char b[100];
    scanf("%ld", &a);
    scanf("%s", b);
    int length = strlen(b);
    char bStr[100] = "";
    for (int i = 0; i < length; i++) {
        if (b[i] != '.') {
            strncat(bStr, &b[i], 1);
        }
    }
    int bInt = atoi(bStr);
    long result = (a * bInt) / 100;
    printf("%ld\n", result);
    return 0;
}
