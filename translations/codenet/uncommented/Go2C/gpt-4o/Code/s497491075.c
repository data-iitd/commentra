#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void run(FILE *input, FILE *output) {
    int N, D;
    fscanf(input, "%d %d", &N, &D);

    int count = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        fscanf(input, "%d %d", &x, &y);
        double d = sqrt(x * x + y * y);
        if (D >= d) {
            count++;
        }
    }
    fprintf(output, "%d\n", count);
}

int main() {
    run(stdin, stdout);
    return 0;
}

/* <END-OF-CODE> */
