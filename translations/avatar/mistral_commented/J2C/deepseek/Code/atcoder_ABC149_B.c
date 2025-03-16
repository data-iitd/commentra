#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int64;

typedef struct {
    int64 A, B, K;
    int64 x, y;
} Main;

void calc(Main *main) {
    main->x = main->A;
    main->y = main->B;

    main->x = main->A - main->K;

    if (main->x < 0) {
        main->y = main->B + main->x;
        main->x = 0;
    }

    if (main->y < 0) {
        main->y = 0;
    }
}

void showResult(Main *main) {
    printf("%lld %lld\n", main->x, main->y);
}

int main() {
    Main main;
    char input[100];
    char *token;

    if (fgets(input, sizeof(input), stdin) != NULL) {
        token = strtok(input, " ");
        main.A = atoll(token);
        token = strtok(NULL, " ");
        main.B = atoll(token);
        token = strtok(NULL, " ");
        main.K = atoll(token);
    }

    calc(&main);
    showResult(&main);

    return 0;
}

