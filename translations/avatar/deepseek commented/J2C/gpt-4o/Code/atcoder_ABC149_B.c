#include <stdio.h>

typedef struct {
    long A;
    long B;
    long K;
    long x;
    long y;
} Main;

void calc(Main *ins) {
    ins->x = ins->A;
    ins->y = ins->B;
    ins->x = ins->A - ins->K; // Subtract K from A to get the new value of x
    if (ins->x < 0) {
        ins->y = ins->B + ins->x; // Adjust B by the negative value of x
        ins->x = 0; // Set x to 0 if it becomes negative
        if (ins->y < 0) {
            ins->y = 0; // Set y to 0 if it becomes negative
        }
    }
}

void showResult(Main *ins) {
    printf("%ld %ld\n", ins->x, ins->y); // Print the final values of x and y
}

int main() {
    Main ins;
    scanf("%ld %ld %ld", &ins.A, &ins.B, &ins.K); // Read A, B, K from input
    calc(&ins);
    showResult(&ins);
    return 0;
}

// <END-OF-CODE>
