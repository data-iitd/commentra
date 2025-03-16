
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    double x[N];
    for (int i = 0; i < N; i++) {
        char s[100];
        scanf("%s", s);
        if (strstr(s, "JPY")) {
            s[strstr(s, "JPY") - s] = '*';
            s[strstr(s, "JPY") - s + 1] ='';
            s[strstr(s, "JPY") - s + 2] = '1';
            s[strstr(s, "JPY") - s + 3] = '.';
            s[strstr(s, "JPY") - s + 4] = '0';
        }
        if (strstr(s, "BTC")) {
            s[strstr(s, "BTC") - s] = '*';
            s[strstr(s, "BTC") - s + 1] ='';
            s[strstr(s, "BTC") - s + 2] = '3';
            s[strstr(s, "BTC") - s + 3] = '8';
            s[strstr(s, "BTC") - s + 4] = '0';
            s[strstr(s, "BTC") - s + 5] = '0';
            s[strstr(s, "BTC") - s + 6] = '0';
            s[strstr(s, "BTC") - s + 7] = '0';
        }
        x[i] = atof(s);
    }
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }
    printf("%.2lf\n", sum);
    return 0;
}

