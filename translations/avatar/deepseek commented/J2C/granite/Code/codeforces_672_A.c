

#include <stdio.h>
#include <string.h>

char *generateString() {
    char *str = (char *)malloc(1001 * sizeof(char));
    for (int i = 1; i <= 1000; i++) {
        sprintf(str + i - 1, "%d", i);
    }
    return str;
}

int main() {
    int n;
    scanf("%d", &n);
    char *str = generateString();
    printf("%c\n", str[n - 1]);
    free(str);
    return 0;
}

