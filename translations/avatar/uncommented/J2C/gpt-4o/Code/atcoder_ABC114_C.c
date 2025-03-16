#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long N;
    scanf("%ld", &N);
    long i = 357;
    int c = 0;

    while (i <= N) {
        char s[20];
        sprintf(s, "%ld", i);
        
        // Check if the string contains '3', '5', and '7'
        if (strchr(s, '3') && strchr(s, '5') && strchr(s, '7')) {
            c++;
        }

        // Create the new number based on the rules
        char sb[20];
        int f = 0;
        int len = strlen(s);
        int sb_index = 0;

        for (int j = len - 1; j >= 0; j--) {
            char a = s[j];
            if (f) {
                sb[sb_index++] = a;
            } else {
                if (a == '3') {
                    sb[sb_index++] = '5';
                    f = 1;
                } else if (a == '5') {
                    sb[sb_index++] = '7';
                    f = 1;
                } else {
                    sb[sb_index++] = '3';
                }
            }
        }
        if (!f) {
            sb[sb_index++] = '3';
        }

        // Reverse the string
        for (int j = 0; j < sb_index / 2; j++) {
            char temp = sb[j];
            sb[j] = sb[sb_index - 1 - j];
            sb[sb_index - 1 - j] = temp;
        }
        sb[sb_index] = '\0'; // Null-terminate the string

        // Convert the new string back to a long
        i = strtol(sb, NULL, 10);
    }

    printf("%d\n", c);
    return 0;
}

/* <END-OF-CODE> */
