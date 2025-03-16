#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[100];
    scanf("%s", str);

    int max = 0, cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T') {
            cnt++;
        } else {
            cnt = 0;
        }
        max = max < cnt ? cnt : max;
    }

    printf("%d\n", max);
}

