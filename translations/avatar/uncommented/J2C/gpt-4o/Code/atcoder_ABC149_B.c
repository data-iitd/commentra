#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long A, B, K;
    long x, y;
} Main;

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

int main() {
    Main ins;
    scanf("%ld %ld %ld", &ins.A, &ins.B, &ins.K);
    calc(&ins);
    showResult(&ins);
    return 0;
}

// <END-OF-CODE>
