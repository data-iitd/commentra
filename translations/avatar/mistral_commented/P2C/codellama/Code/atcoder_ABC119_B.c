#include <stdio.h>

int main() {
    int N;
    float x[1000];
    int i;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        char input[100];
        scanf("%s", input);
        if (input[0] == 'J') {
            x[i] = atof(input + 1) * 1.0;
        } else {
            x[i] = atof(input + 1) * 380000.0;
        }
    }

    float sum = 0;
    for (i = 0; i < N; i++) {
        sum += x[i];
    }

    printf("%.2f\n", sum);

    return 0;
}

