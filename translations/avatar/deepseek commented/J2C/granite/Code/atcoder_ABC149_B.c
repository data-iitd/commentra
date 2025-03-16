
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long A, B, K;
    long x, y;
} Main;

int main(int argc, char *argv[]) {
    Main ins;
    ins.A = atol(argv[1]);
    ins.B = atol(argv[2]);
    ins.K = atol(argv[3]);
    ins.calc();
    ins.showResult();
    return 0;
}

void calc(Main *ins) {
    ins->x = ins->A;
    ins->y = ins->B;
    ins->x = ins->A - ins->K;
    if (ins->x < 0) {
        ins->y = ins->B + ins->x;
        ins->x = 0;
        if (ins->y < 0) {
            ins->y = 0;
        }
    }
}

void showResult(Main *ins) {
    printf("%ld %ld\n", ins->x, ins->y);
}

