#include <stdio.h>
<<<<<<< HEAD
=======
#include <limits.h>
>>>>>>> 98c87cb78a (data updated)

int main() {
    long long N, X;
    scanf("%lld %lld", &N, &X);

    long long ans = 0;
    long long min = 1000000000;
    for (int i = 0; i < N; i++) {
        long long tmp;
        scanf("%lld", &tmp);
        X -= tmp;
        ans++;
        if (tmp < min) min = tmp;
    }

    ans += X / min;

    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
