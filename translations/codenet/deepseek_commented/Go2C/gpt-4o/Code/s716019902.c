#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
const int mod = 998244353;

int main() {
    int N;
    scanf("%d", &N);
    long long sum = 0;
=======
#define MOD 998244353
#define FAC_NUM 300001

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    
>>>>>>> 98c87cb78a (data updated)
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }
<<<<<<< HEAD
    printf("%lld\n", sum);
=======
    
    printf("%d\n", sum);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
