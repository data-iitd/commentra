
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void Main::calc() {
x = A;
y = B;
x = A - K;
if (x < 0) {
y = B + x;
x = 0;
if (y < 0) {
y = 0;
}
}
}

void Main::showResult() {
printf("%ld %ld\n", x, y);
}

