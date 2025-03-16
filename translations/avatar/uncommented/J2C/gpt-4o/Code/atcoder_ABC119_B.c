#include <stdio.h>
#include <string.h>

double solve(double x[], char u[][4], int N) {
    double total = 0.0;
    for (int i = 0; i < N; ++i) {
        if (strcmp(u[i], "JPY") == 0) {
            total += x[i];
        } else {
            total += x[i] / 380000.0;
        }
    }
    return total;
}

int main() {
    int N;
    scanf("%d", &N);
    
    double x[N];
    char u[N][4]; // Assuming currency codes are at most 3 characters + null terminator

    for (int i = 0; i < N; ++i) {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }

    printf("%.6f\n", solve(x, u, N));
    return 0;
}

// <END-OF-CODE>
