#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (B - A == C - B) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

// Max, Min functions
int IntMax(int a, int b) {
    return (a < b) ? b : a;
}

long long Int64Max(long long a, long long b) {
    return (a < b) ? b : a;
}

double Float64Max(double a, double b) {
    return (a < b) ? b : a;
}

int IntMin(int a, int b) {
    return (a > b) ? b : a;
}

long long Int64Min(long long a, long long b) {
    return (a > b) ? b : a;
}

double Float64Min(double a, double b) {
    return (a > b) ? b : a;
}

// GCD functions
int IntGcd(int a, int b) {
    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }
    if (b == 0) {
        return a;
    }
    return IntGcd(b, a % b);
}

long long Int64Gcd(long long a, long long b) {
    if (a < b) {
        long long temp = b;
        b = a;
        a = temp;
    }
    if (b == 0) {
        return a;
    }
    return Int64Gcd(b, a % b);
}

int IntAbs(int a) {
    return (a < 0) ? -a : a;
}

long long Int64Abs(long long a) {
    return (a < 0) ? -a : a;
}

// <END-OF-CODE>
