#include <stdio.h>

int main() {
    long x, y, a, b;
    scanf("%ld %ld %ld %ld", &x, &y, &a, &b);
    
    long j = 2, i, x1 = 0, y1 = 0, c = 0;
    int ans = 1; // true
    c = (x > y) ? x : y; // max(x, y)
    
    if (c > b) {
        printf("0\n");
        ans = 0; // false
    }
    
    while (c % ((x < y) ? x : y) != 0 && ans) {
        if (x > y) {
            c = x * j;
            j++;
        } else {
            c = y * j;
            j++;
        }
        if (c > b) {
            printf("0\n");
            ans = 0; // false
            break;
        }
    }
    
    if (ans) {
        long count = 0;
        for (i = a; i <= b; i++) {
            if (i % c == 0) break;
        }
        if (i != b + 1) {
            printf("%ld\n", (b - i) / c + 1);
        } else {
            printf("0\n");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
