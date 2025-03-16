#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define IOS ios_base::sync_with_stdio(0), scanf("%d", &t), scanf("%d", &t), scanf("%d", &t);
#define prec printf("%0.15f\n", 
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define ssort(z, n) qsort(z, n, sizeof(int), (int (*)(const void *, const void *))int_cmp);
#define rsort(z, n) qsort(z, n, sizeof(int), (int (*)(const void *, const void *))int_cmp_rev);
#define eerase(z, n) qsort(z, n, sizeof(int), (int (*)(const void *, const void *))int_cmp); z = unique(z, z + n);
#define ccnt(z, w, n) count(z, z + n, w)
#define rep(i,a,n) for(Int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(Int (i)=(a); (i)<=(n); (i)++)
const int MAX_N = 1000000;
const Int MAX_N_Int = 1000000000000;

int int_cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int int_cmp_rev(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

bool isPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b;
    //a*bは64bit integer overflow
}

int Max(int a, int b, int c) {
    int temp = a > b ? a : b;
    return temp > c ? temp : c;
}

int Min(int a, int b, int c) {
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}

bool integer(double num) {
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
    for(Int i = 2; i <= n; i++) {
        f = f * (i % MOD) % MOD;
    }
    return f;
}

// 繰り返し二乗法 (modの世界での累乗)
Int mod_pow(Int x, Int n, Int mod) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

// 組み合わせ nCr を求める
Int combination_mod(Int n, Int r, Int mod) {
    if(r > n-r) r = n-r;
    if(r == 0) return 1;
    Int a = 1;
    for(Int i = 0; i < r; i++) {
        a = a * ((n-i) % mod) % mod;
    }
    Int b = mod_pow(fact_mod(r, mod), mod-2, mod);
    return (a % mod) * (b % mod) % mod;
}

bool rev(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len / 2; i++) {
        if(s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    Int a, b, c, n, m, k, x, y = 0, ans = 0;
    char str[100], s[100], t[100], u[100];
    scanf("%d %d %d", &k, &a, &b);
    for (int i = a; i <= b; ++i) {
        if (i % k == 0) {
            printf("OK\n");
            return 0;
        }
    }
    printf("NG\n");
    return 0;
}
