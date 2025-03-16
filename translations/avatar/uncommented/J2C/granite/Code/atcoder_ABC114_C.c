
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    long i = 357;
    int c = 0;
    while (i <= N) {
        char s[20];
        sprintf(s, "%ld", i);
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7")) {
            c++;
        }
        char t[20];
        int f = 0;
        for (int j = strlen(s) - 1; j >= 0; j--) {
            if (f) {
                t[strlen(s) - 1 - j] = s[strlen(s) - 1 - j];
            } else {
                if (s[strlen(s) - 1 - j] == '3') {
                    t[strlen(s) - 1 - j] = '5';
                    f = 1;
                } else if (s[strlen(s) - 1 - j] == '5') {
                    t[strlen(s) - 1 - j] = '7';
                    f = 1;
                } else {
                    t[strlen(s) - 1 - j] = '3';
                }
            }
        }
        if (!f) {
            t[0] = '3';
        }
        long j;
        sscanf(t, "%ld", &j);
        i = j;
    }
    printf("%d\n", c);
    return 0;
}
//END-OF-CODE