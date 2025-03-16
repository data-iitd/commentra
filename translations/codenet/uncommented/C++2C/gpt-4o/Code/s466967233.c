#include <stdio.h>
<<<<<<< HEAD

#define MAX_SIZE 200100

typedef long long ll;

int main() {
    ll N, K;
    ll A[MAX_SIZE];
    ll B[MAX_SIZE];
    int now = 1;
    ll cnt = 0;
    ll j;

    // Initialize B array
=======
#include <stdlib.h>

#define MAX_SIZE 200100

int main() {
    long long N, K;
    long long A[MAX_SIZE];
    long long B[MAX_SIZE];
    int now = 1;
    long long cnt = 0;
    long long j;

    // Initialize B array to -1
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < MAX_SIZE; i++) {
        B[i] = -1;
    }

    // Read input values
    scanf("%lld %lld", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    // Set the starting point
    B[1] = 0;
    for (j = 1; j <= K; j++) {
        now = A[now];
        if (B[now] == -1) {
            B[now] = j;
        } else {
            cnt = j;
            break;
        }
    }

    if (j < K) {
<<<<<<< HEAD
        ll tmp;
        tmp = (K - B[now]) % (cnt - B[now]);
        for (ll i = 0; i < tmp; i++) {
=======
        long long tmp;
        tmp = (K - B[now]) % (cnt - B[now]);
        for (long long i = 0; i < tmp; i++) {
>>>>>>> 98c87cb78a (data updated)
            now = A[now];
        }
    }

    printf("%lld\n", now);
    return 0;
}

// <END-OF-CODE>
