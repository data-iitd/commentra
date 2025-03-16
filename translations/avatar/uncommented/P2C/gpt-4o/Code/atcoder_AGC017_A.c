#include <stdio.h>

long long combi(int N, int K) {
    long long a = 1;
    for (int i = 0; i < K; i++) {
        a *= (N - i);
    }
    for (int j = 0; j < K; j++) {
        a /= (j + 1);
    }
    return a;
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);
    
    int lis[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lis[i]);
    }
    
    int ls[N];
    for (int i = 0; i < N; i++) {
        ls[i] = lis[i] % 2;
    }
    
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++) {
        if (ls[i] == 1) {
            one++;
        } else {
            zero++;
        }
    }
    
    long long pattern_a = 0;
    long long pattern_b = 0;
    
    for (int j = 0; j <= zero; j++) {
        pattern_b += combi(zero, j);
    }
    
    for (int time = 0; time <= one; time++) {
        if (time % 2 == P) {
            pattern_a += combi(one, time);
        }
    }
    
    printf("%lld\n", pattern_a * pattern_b);
    
    return 0;
}

// <END-OF-CODE>
