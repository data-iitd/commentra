#include <stdio.h>

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

int main() {
    long long a[4];
    
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &a[i]);
    }
    
    long long result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])));
    printf("%lld\n", result);
    
    return 0;
}

// <END-OF-CODE>
