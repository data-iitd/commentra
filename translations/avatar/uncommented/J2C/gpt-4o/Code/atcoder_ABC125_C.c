#include <stdio.h>

int A[100000]; // Assuming a maximum size for the array
int L[100000];
int R[100000];

int gcd(int a, int b) {
    int tmp;
    if (b > a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0) {
        return a;
    }
    int r = -1;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    return a;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    L[0] = A[0];
    for (int i = 1; i < N; i++) {
        L[i] = gcd(L[i - 1], A[i]);
    }

    R[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        R[i] = gcd(R[i + 1], A[i]);
    }

    int answer = (N > 1) ? (L[N - 2] > R[1] ? L[N - 2] : R[1]) : L[0];
    for (int i = 1; i < N - 1; i++) {
        answer = (answer > gcd(L[i - 1], R[i + 1]) ? answer : gcd(L[i - 1], R[i + 1]));
    }

    printf("%d\n", answer);
    return 0;
}

// <END-OF-CODE>
