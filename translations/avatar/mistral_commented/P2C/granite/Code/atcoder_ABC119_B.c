
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    double x[N];
    for (int i = 0; i < N; i++) {
        char buf[1024];
        scanf("%s", buf);
        if (strstr(buf, "JPY")) {
            x[i] = atof(strtok(buf, "JPY")) * 1.0;
        } else if (strstr(buf, "BTC")) {
            x[i] = atof(strtok(buf, "BTC")) * 380000.0;
        }
    }

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }

    printf("%f\n", sum);

    return 0;
}
// 