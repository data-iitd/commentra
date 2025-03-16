#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[100000];
    scanf("%s", a);
    int count = 0;
    int i = 0;
    while (a[i]!= '\0') {
        if (a[i] == '1') {
            count = count * (i - count + 1);
        }
        i++;
    }
    printf("%d", count);
    return 0;
}

