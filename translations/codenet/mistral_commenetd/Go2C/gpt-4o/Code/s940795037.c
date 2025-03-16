#include <stdio.h>
#include <stdlib.h>

double calculate_harmonic_mean(int n) {
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        ans += 1.0 / tmp;
    }
    return 1.0 / ans;
}

int main() {
    int n;
    // Reading the first integer from the standard input
    scanf("%d", &n);
    
    // Calculating the harmonic mean
    double result = calculate_harmonic_mean(n);
    
    // Printing the final answer
    printf("%lf\n", result);
    
    return 0;
}

/* <END-OF-CODE> */
