#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("Hello World");
    } else {
        char str1[1000], str2[1000];
        scanf("%s", str1);
        scanf("%s", str2);
        printf("%d", atoi(str1) + atoi(str2));
    }
    return 0;
}
