#include <stdio.h>
#include <string.h>

int main() {
    char str[100000];
    char c[100000];
    long k;
    int n;

    scanf("%s", str);
    strcpy(c, str);
    scanf("%ld", &k);
    n = strlen(str);

    for (int i = 0; i < k; i++) {
        if (c[i] == '1') {
            if (i == k - 1) {
                printf("1\n");
                return 0;
            }
        } else {
            printf("%c\n", c[i]);
            return 0;
        }
    }

    return 0;
}
