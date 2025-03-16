#include <stdio.h>
#include <math.h>

int main() {
    long n;
    scanf("%ld", &n);
    
    int sqrt_n = (int) sqrt(n);
    int answer = 0;

    for (int i = 2; i <= sqrt_n; i++) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        for (int j = 1; count - j >= 0; j++) {
            count -= j;
            answer++;
        }
    }
    
    if (n > 1) {
        answer++;
    }
    
    printf("%d\n", answer);
    return 0;
}

// <END-OF-CODE>
