
#include <stdio.h>
#include <math.h>

void Run(FILE *r, FILE *w) {
    int N, D;
    fscanf(r, "%d %d", &N, &D);

    int count = 0;
    int x, y;
    for (int i = 0; i < N; i++) {
        fscanf(r, "%d %d", &x, &y);
        double distance = sqrt(x * x + y * y);
        if (distance <= D) {
            count++;
        }
    }

    fprintf(w, "%d\n", count);
}

int main() {
    Run(stdin, stdout);
}

// END-OF-CODE