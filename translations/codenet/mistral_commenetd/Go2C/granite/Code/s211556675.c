
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int id, num;
} Val;

typedef struct {
    int A, B, C, K;
} Input;

int max(int a, int b, int c) {
    int m = a;
    if (m < b) m = b;
    if (m < c) m = c;
    return m;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int main() {
    Input input;
    scanf("%d %d %d %d", &input.A, &input.B, &input.C, &input.K);

    int ma = max(input.A, input.B, input.C);
    int rest = 0;
    if (ma == input.A) {
        rest += input.B + input.C;
    } else if (ma == input.B) {
        rest += input.A + input.C;
    } else {
        rest += input.A + input.B;
    }

    int answer = pow(ma, input.K) + rest;

    printf("%d\n", answer);

    return 0;
}
