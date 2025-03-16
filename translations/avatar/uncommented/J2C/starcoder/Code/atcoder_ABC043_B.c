#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);
    int i = 0;
    char d[100000];
    while (s[i]!= '\0') {
        switch (s[i]) {
            case '0':
                d[i] = '0';
                break;
            case '1':
                d[i] = '1';
                break;
            case 'B':
                if (i > 0) {
                    i--;
                }
                break;
        }
        i++;
    }
    d[i] = '\0';
    printf("%s\n", d);
    return 0;
}

