#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits.h>

const long long MOD = 1e9 + 7;

int getInt() {
    int i;
    std::cin >> i;
    return i;
}

std::string getString() {
    std::string str;
    std::cin >> str;
    return str;
}

long long calcMod(long long x) {
    return x % MOD;
}

bool isPrime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int N = getInt();
    int sqrtN = static_cast<int>(std::sqrt(N));

    int min = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        if (num < min) {
            min = num;
        }
    }

    std::cout << min << std::endl;

    return 0;
}
