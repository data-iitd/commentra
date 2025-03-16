#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int gi() {
    int value;
    scanf("%d", &value);
    return value;
}

long gl() {
    long value;
    scanf("%ld", &value);
    return value;
}

char* gs() {
    char* buffer = (char*)malloc(100 * sizeof(char));
    scanf("%s", buffer);
    return buffer;
}

void main() {
    int N = gi();
    long i = 357;
    int c = 0;

    while (i <= N) {
        char str[20];
        sprintf(str, "%ld", i);

        if (strstr(str, "3") && strstr(str, "5") && strstr(str, "7")) {
            c++;
        }

        char* sb = (char*)malloc(20 * sizeof(char));
        bool f = false;

        for (int j = 0; j < strlen(str); j++) {
            char a = str[strlen(str) - 1 - j];

            if (f) {
                sb[j] = a;
            } else {
                if (a == '3') {
                    sb[j] = '5';
                    f = true;
                } else if (a == '5') {
                    sb[j] = '7';
                    f = true;
                } else {
                    sb[j] = '3';
                }
            }
        }

        if (!f) {
            sb[strlen(str)] = '3';
            sb[strlen(str) + 1] = '\0';
        }

        char* sb2 = (char*)malloc(20 * sizeof(char));
        strcpy(sb2, sb);
        for (int j = 0; j < strlen(sb2) / 2; j++) {
            char temp = sb2[j];
            sb2[j] = sb2[strlen(sb2) - 1 - j];
            sb2[strlen(sb2) - 1 - j] = temp;
        }

        i = atol(sb2);
        free(sb);
        free(sb2);
    }

    printf("%d\n", c);
}
