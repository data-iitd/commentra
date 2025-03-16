#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <string>

const long long MOD = 1e9 + 7;

int getInt() {
    int i;
    std::cin >> i;
    return i;
}

std::string getString() {
    std::string s;
    std::cin >> s;
    return s;
}

long long powMod(long long n, long long p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        long long t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

long long calcMod(long long x) {
    return x % MOD;
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = std::sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int N = getInt();
    int sqrtN = std::sqrt(N);

    int min = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) continue;

        int num = i + (N / i) - 2;
        if (num < min) min = num;
    }

    std::cout << min << std::endl;

    return 0;
}

