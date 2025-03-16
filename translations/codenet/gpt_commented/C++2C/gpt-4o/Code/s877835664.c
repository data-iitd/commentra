#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

<<<<<<< HEAD
void getPrimeFactor(ll n, ll *factors, ll *counts, ll *size) {
    *size = 0;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[*size] = i;
            counts[*size]++;
            n /= i;
            if (counts[*size] == 1) (*size)++;
        }
    }
    if (n != 1) {
        factors[*size] = n;
        counts[*size] = 1;
        (*size)++;
    }
=======
void getPrimeFactor(ll n) {
    // This function is not used in the main logic, so it's left empty.
>>>>>>> 98c87cb78a (data updated)
}

int IsPrimeNumber(ll num) {
    if (num <= 2) return 1; // 0, 1, and 2 are considered prime
    else if (num % 2 == 0) return 0; // Exclude even numbers

    double sqrtNum = sqrt(num);
<<<<<<< HEAD
    for (int i = 3; i <= sqrtNum; i += 2) {
=======
    for (ll i = 3; i <= sqrtNum; i += 2) {
>>>>>>> 98c87cb78a (data updated)
        if (num % i == 0) {
            return 0; // Found a factor, not prime
        }
    }

    return 1; // No factors found, num is prime
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; 
        long long temp = a; a = b; b = temp; // Swap a and b
        u -= t * v; 
        temp = u; u = v; v = temp; // Update u and v
    }
    u %= m; 
    if (u < 0) u += m; 
    return u; 
}

int main() {
    ll N, K;
<<<<<<< HEAD
    scanf("%lld %lld", &N, &K);

    ll *A = (ll *)malloc((N + 1) * sizeof(ll));
=======
    // Input the number of elements and the value of K
    scanf("%lld %lld", &N, &K);

    ll *A = (ll *)malloc((N + 1) * sizeof(ll));
    // Input the elements into the array A
>>>>>>> 98c87cb78a (data updated)
    for (ll i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

<<<<<<< HEAD
    ll cur = 1; 
=======
    ll cur = 1; // Initialize current position
>>>>>>> 98c87cb78a (data updated)
    ll *dic = (ll *)malloc((N + 1) * sizeof(ll));
    for (ll i = 0; i <= N; i++) dic[i] = -1; // Initialize dictionary
    int flg = 0; // Flag to indicate if we have entered a cycle

<<<<<<< HEAD
    for (ll i = 1; i <= K; i++) {
        if (dic[cur] < 0 || flg) {
            dic[cur] = i; 
            cur = A[cur]; 
        } else if (!flg) {
            ll tmp = K - (dic[cur] - 1); 
            tmp %= i - dic[cur]; 
            i = K - tmp; 
            flg = 1; 
        }
    }

    printf("%lld\n", cur);
    
    free(A);
    free(dic);
    return 0; 
=======
    // Process the sequence based on the value of K
    for (ll i = 1; i <= K; i++) {
        // If current index has not been seen before or we are in a cycle
        if (dic[cur] < 0 || flg) {
            dic[cur] = i; // Record the current index
            cur = A[cur]; // Move to the next index
        }
        // If we have seen this index before and are not in a cycle
        else if (!flg) {
            ll tmp = K - (dic[cur] - 1); // Calculate remaining steps
            tmp %= i - dic[cur]; // Adjust steps based on the cycle length
            i = K - tmp; // Update i to skip to the end of the cycle
            flg = 1; // Set the flag indicating we are in a cycle
        }
    }

    // Output the final position after K steps
    printf("%lld\n", cur);

    // Free allocated memory
    free(A);
    free(dic);
    
    return 0; // End of the program
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
