#include <stdio.h>
#include <math.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the number of combinations of choosing K items from a set of N items
unsigned long long combi(int N, int K) {
    if (K > N) return 0;
    if (K == 0 || K == N) return 1;
    unsigned long long num = factorial(N);
    unsigned long long den = factorial(K) * factorial(N - K);
    return num / den;
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
        if (ls[i] == 1) one++;
        else zero++;
    }

    unsigned long long pattern_a = 0, pattern_b = 0;

    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }

    int time = 0;
    while (time <= one) {
        if (time % P == 0) {
            pattern_a += combi(one, time);
        }
        time++;
    }

    printf("%lld\n", pattern_a * pattern_b);

    return 0;
}
