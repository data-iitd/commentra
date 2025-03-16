#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    long i = 357;
    int c = 0;
    while (i <= N) {
        char s[100];
        sprintf(s, "%ld", i);
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7")) {
            c++;
        }
        char s2[100];
        sprintf(s2, "%ld", i);
        int l = strlen(s2);
        int f = 0;
        for (int j = 0; j < l; j++) {
            if (f) {
                strcat(s2, s2[l - 1 - j]);
            } else {
                if (s2[l - 1 - j] == '3') {
                    strcat(s2, '5');
                    f = 1;
                } else if (s2[l - 1 - j] == '5') {
                    strcat(s2, '7');
                    f = 1;
                } else {
                    strcat(s2, '3');
                }
            }
        }
        if (!f) strcat(s2, '3');
        char s3[100];
        sprintf(s3, "%s", s2);
        int l2 = strlen(s3);
        for (int j = 0; j < l2 / 2; j++) {
            char a = s3[j];
            s3[j] = s3[l2 - 1 - j];
            s3[l2 - 1 - j] = a;
        }
        i = atol(s3);
    }
    printf("%d\n", c);
    return 0;
}

