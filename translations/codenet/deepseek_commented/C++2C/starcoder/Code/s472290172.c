#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100000];
    scanf("%s", str);
    int max = 0, cnt = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        if (str[i] == 'A' || str[i] == 'C' || str[i] == 'G' || str[i] == 'T') {
            cnt++;
        } else {
            cnt = 0;
        }
        max = max < cnt? cnt : max;
    }
    printf("%d\n", max);
}
