#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007

long long gcd(long long a, long long b) {
    return b != 0 ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

bool isPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

<<<<<<< HEAD
=======
long long fact(int num) {
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

long long yakusu(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}

>>>>>>> 98c87cb78a (data updated)
long long fact_mod(long long n, long long mod) {
    long long f = 1;
    for (long long i = 2; i <= n; i++) {
        f = f * (i % MOD) % MOD;
    }
    return f;
}

long long mod_pow(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

long long combination_mod(long long n, long long r, long long mod) {
    if (r > n - r) r = n - r;
    if (r == 0) return 1;
    long long a = 1;
    for (long long i = 0; i < r; i++) {
        a = a * ((n - i) % mod) % mod;
    }
    long long b = mod_pow(fact_mod(r, mod), mod - 2, mod);
    return (a % mod) * (b % mod) % mod;
}

<<<<<<< HEAD
=======
bool rev(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}

>>>>>>> 98c87cb78a (data updated)
int main() {
    long long a, b, k;
    scanf("%lld %lld %lld", &k, &a, &b);
    for (long long i = a; i <= b; ++i) {
        if (i % k == 0) {
            printf("OK\n");
            return 0;
        }
    }
    printf("NG\n");
    return 0;
}

<<<<<<< HEAD
/* 
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/

=======
/* <END-OF-CODE> */
>>>>>>> 98c87cb78a (data updated)
