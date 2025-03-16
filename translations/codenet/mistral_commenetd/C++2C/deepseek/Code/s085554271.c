#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec std::cout << std::fixed << std::setprecision(15);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define ssort(z) qsort(z, sizeof(z)/sizeof(*z), sizeof(*z), (int (*)(const void *, const void *))comparator)
#define rsort(z) qsort(z, sizeof(z)/sizeof(*z), sizeof(*z), (int (*)(const void *, const void *))rcomparator)
#define eerase(z) qsort(z, sizeof(z)/sizeof(*z), sizeof(*z), (int (*)(const void *, const void *))unique_comparator)
#define rep(i,a,n) for(Int i=(a); i<(n); i++)
#define repq(i,a,n) for(Int i=(a); i<=(n); i++)

const int MAX_N = 1000000;
const Int MAX_N_Int = 1000000000000;

int comparator(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int rcomparator(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int unique_comparator(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void printV(const int* v, const char * const separator, size_t size) {
    if(size > 0) {
        for(size_t i = 0; i < size - 1; i++) {
            printf("%d%s", v[i], separator);
        }
        printf("%d\n", v[size - 1]);
    }
}

int isPrime(int num) {
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b;
}

int Max(int a, int b, int c) {
    int temp = a > b ? a : b;
    return temp > c ? temp : c;
}

int Min(int a, int b, int c) {
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}

int integer(double num) {
    return floor(num) == num;
}

Int fact(int num) {
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

Int yakusu(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}

Int fact_mod(Int n, Int mod) {
    Int f = 1;
    rep(i, 0, n) f = f * (i % MOD) % MOD;
    return f;
}

Int mod_pow(Int x, Int n, Int mod) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

Int combination_mod(Int n, Int r, Int mod) {
    if(r > n-r) r = n-r;
    if(r == 0) return 1;
    Int a = 1;
    rep(i, 0, r) a = a * ((n-i) % MOD) % MOD;
    Int b = mod_pow(fact_mod(r, mod), mod-2, mod);
    return (a % MOD) * (b % MOD) % MOD;
}

int rev(const char* s){
    int len = strlen(s);
    for(int i = 0; i < len / 2; i++) {
        if(s[i] != s[len - i - 1]) return 0;
    }
    return 1;
}

int main() {
    Int k, a, b;
    scanf("%ld %ld %ld", &k, &a, &b);

    for (int i = a; i <= b; ++i) {
        if(i % k == 0){
            printf("OK\n");
            return 0;
        }
    }

    printf("NG\n");

    return 0;
}
