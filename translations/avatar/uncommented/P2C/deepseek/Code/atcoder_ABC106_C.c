#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX_LEN 100000

int main() {
    char s[MAX_LEN + 1];
    int k;
    scanf("%s", s);
    scanf("%d", &k);

    int l = 0;
    while (s[l] == '1') {
        l++;
    }

    if (l >= k) {
        printf("1\n");
    } else {
        printf("%c\n", s[l]);
    }

    return 0;
}

