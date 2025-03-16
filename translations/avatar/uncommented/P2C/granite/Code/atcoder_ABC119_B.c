
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    double x[N];
    for (int i = 0; i < N; i++) {
        char buf[1024];
        scanf("%s", buf);
        char *p = buf;
        while (*p!= '\0') {
            if (*p == 'J') {
                *p = '*';
                *(p + 1) = '1';
                *(p + 2) = '.';
                *(p + 3) = '0';
            } else if (*p == 'B') {
                *p = '*';
                *(p + 1) = '3';
                *(p + 2) = '8';
                *(p + 3) = '0';
                *(p + 4) = '0';
                *(p + 5) = '0';
                *(p + 6) = '0';
            }
            p++;
        }
        x[i] = atof(buf);
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }
    printf("%f\n", sum);
    return 0;
}
// 