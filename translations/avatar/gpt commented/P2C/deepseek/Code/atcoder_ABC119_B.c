#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    double total = 0.0;
    char input[100];

    for (int i = 0; i < N; i++) {
        scanf("%s", input);
        char *token = strtok(input, " ");
        while (token != NULL) {
            if (strcmp(token, "JPY") == 0) {
                total += 1.0;
            } else if (strcmp(token, "BTC") == 0) {
                total += 380000.0;
            } else {
                total += atof(token);
            }
            token = strtok(NULL, " ");
        }
    }

    printf("%.10f\n", total);
    return 0;
}
