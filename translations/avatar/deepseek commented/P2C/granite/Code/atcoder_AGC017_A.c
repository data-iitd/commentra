
#include <stdio.h>
#include <math.h>

// Define a function to calculate the binomial coefficient
double combi(int N, int K) {
    double a = 1;
    // Calculate the product part of the binomial coefficient
    for (int i = 0; i < K; i++) {
        a *= N - i;
    }
    // Calculate the division part of the binomial coefficient
    for (int j = 0; j < K; j++) {
        a /= j + 1;
    }
    return a;
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);

    int ans = 0;
    int lis[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }

    int ls[N];
    for (int i = 0; i < N; i++) {
        ls[i] = lis[i] % 2;
    }

    int one = 0;
    int zero = 0;
    for (int i = 0; i < N; i++) {
        if (ls[i] == 1) {
            one++;
        } else {
            zero++;
        }
    }

    double pattern_a = 0;
    double pattern_b = 0;
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

    printf("%d\n", (int)(pattern_a * pattern_b));

    return 0;
}
