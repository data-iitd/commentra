#include <stdio.h>
#include <stdlib.h>

// Function to calculate factorial
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate combinations C(N, K)
int combi(int N, int K) {
    int a = factorial(N);
    int b = factorial(K);
    int c = factorial(N - K);
    return a / (b * c);
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    int lis[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }

    int ls[N];
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
        ls[i] = lis[i] % 2;
        if (ls[i] == 1) {
            one++;
        } else {
            zero++;
        }
    }

    int pattern_a = 0, pattern_b = 0;
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    int time = 0;
    while (time <= one) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
        time++;
    }

    printf("%d\n", pattern_a * pattern_b);
    return 0;
}
