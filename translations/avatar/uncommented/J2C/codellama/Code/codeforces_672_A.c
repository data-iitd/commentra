
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generateString() {
    char *str = (char *)malloc(1000 * sizeof(char));
    int i;
    for (i = 0; i < 1000; i++) {
        str[i] = i + '0';
    }
    return str;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%c", generateString()[n - 1]);
    return 0;
}

