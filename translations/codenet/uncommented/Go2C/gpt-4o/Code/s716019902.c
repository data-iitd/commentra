#include <stdio.h>
#include <stdlib.h>

const int mod = 998244353;
const int facNum = 300001;

int main() {
    int N;
    scanf("%d", &N);
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}

// <END-OF-CODE>
