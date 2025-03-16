#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    long long g = gcd(n, m);
    
    char *s = (char *)malloc((n + 1) * sizeof(char));
    char *t = (char *)malloc((m + 1) * sizeof(char));
    
    scanf("%s", s);
    scanf("%s", t);
    
    long long result = (long long)n * m / g;
    for (int k = 0; k < g; k++) {
        if (s[k * n / g] != t[k * m / g]) {
            result = -1;
            break;
        }
    }
    
    printf("%lld\n", result);
    
    free(s);
    free(t);
    
    return 0;
}

// <END-OF-CODE>
