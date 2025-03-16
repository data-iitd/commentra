#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char source[11];
    scanf("%10s", source);

    if (strlen(source) > 10 || strlen(source) < 1) {
        return -1;
    }

    int max_i = (int)pow(2, strlen(source) - 1);

    double sum = 0;

    for (int i = 0; i < max_i; ++i) {
        char plus[100] = {0};
        sprintf(plus, "%b", i);

        double number = 0;

        char working[11];
        strcpy(working, source);
        while (strlen(plus) > 0) {
            int i = 0;
            while (plus[i] == '0') ++i;
            sum += atof(strncpy(working, source, i + 1));
            memmove(plus, plus + i + 1, strlen(plus) - i);
            memmove(working, working + i + 1, strlen(working) - i);
        }
        sum += atof(working);
    }

    printf("%.0f\n", sum);

    return 0;
}
