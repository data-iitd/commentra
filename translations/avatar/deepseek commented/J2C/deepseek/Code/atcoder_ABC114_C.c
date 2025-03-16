#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gi() {
    int num;
    scanf("%d", &num);
    return num;
}

int main() {
    int N = gi();
    long i = 357;
    int c = 0;

    while (i <= N) {
        char s[20];
        sprintf(s, "%ld", i);
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7")) {
            c++;
        }

        char sb[20] = {0};
        int f = 0;
        for (int j = 0; j < strlen(s); j++) {
            char a = s[strlen(s) - 1 - j];
            if (f) {
                sb[j] = a;
            } else {
                if (a == '3') {
                    sb[j] = '5';
                    f = 1;
                } else if (a == '5') {
                    sb[j] = '7';
                    f = 1;
                } else {
                    sb[j] = '3';
                }
            }
        }
        if (!f) {
            sb[strlen(s)] = '3';
        }

        char sb2[20];
        strcpy(sb2, sb);
        strrev(sb2);
        i = atol(sb2);
    }

    printf("%d\n", c);
    return 0;
}
