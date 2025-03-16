#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
#include <math.h>
#include <limits.h>
=======
#include <math.h>
>>>>>>> 98c87cb78a (data updated)

long long a[200005];
long long pre[200005];
long long last[200005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    
    long long sumpre = 0, sumlast = 0;
    for (int i = 1; i < n; i++) {
        sumpre = sumpre + a[i];
        pre[i] = sumpre;
    }
    
    for (int i = n; i > 1; i--) {
        sumlast = sumlast + a[i];
        last[i] = sumlast;
    }
    
    long long d = (1ll << 60);
    for (int i = 1; i < n; i++) {
<<<<<<< HEAD
        d = (d < abs(pre[i] - last[i + 1])) ? d : abs(pre[i] - last[i + 1]);
=======
        d = fmin(d, llabs(pre[i] - last[i + 1]));
>>>>>>> 98c87cb78a (data updated)
    }
    
    printf("%lld\n", d);
    return 0;
}

// <END-OF-CODE>
