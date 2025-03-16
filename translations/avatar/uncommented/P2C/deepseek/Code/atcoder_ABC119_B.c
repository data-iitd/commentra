#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    double x[N];
    char buffer[100];

    for (int i = 0; i < N; i++) {
        scanf("%s", buffer);
        char *token = strtok(buffer, " ");
        double value = 0.0;

        while (token != NULL) {
            if (strcmp(token, "JPY") == 0) {
                value = atof(strtok(NULL, " "));
                break;
            } else if (strcmp(token, "BTC") == 0) {
                value = atof(strtok(NULL, " ")) * 380000.0;
                break;
            }
            token = strtok(NULL, " ");
        }
        x[i] = value;
    }

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }

    printf("%.10f\n", sum);
    return 0;
}
