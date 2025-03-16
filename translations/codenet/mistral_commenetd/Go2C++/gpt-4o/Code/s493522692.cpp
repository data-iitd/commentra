#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <stdexcept>

// Util functions
std::string nextStr() {
    std::string s;
    std::cin >> s;
    return s;
}

int nextInt() {
    int i;
    std::cin >> i;
    if (std::cin.fail()) {
        throw std::runtime_error("Invalid input");
    }
    return i;
}

// Helper functions for mathematical operations
int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

int minInt(int a, int b) {
    return (a < b) ? a : b;
}

int absInt(int a) {
    return (a >= 0) ? a : -a;
}

double absFloat64(double a) {
    return (a >= 0) ? a : -a;
}

double maxFloat64(double a, double b) {
    return (a > b) ? a : b;
}

double minFloat64(double a, double b) {
    return (a < b) ? a : b;
}

int str2Int(const std::string& s) {
    return std::stoi(s);
}

std::string reverse(const std::string& s) {
    std::string reversed(s.rbegin(), s.rend());
    return reversed;
}

int powInt(int p, int q) {
    return static_cast<int>(std::pow(p, q));
}

bool isPrime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i <= std::sqrt(x); i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

std::vector<int> PrimeFactors(int n) {
    std::vector<int> pfs;

    while (n % 2 == 0) {
        pfs.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            pfs.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        pfs.push_back(n);
    }

    return pfs;
}

std::map<int, int> PrimeFactorsMap(int n) {
    std::map<int, int> pfs;

    while (n % 2 == 0) {
        pfs[2]++;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            pfs[i]++;
            n /= i;
        }
    }

    if (n > 2) {
        pfs[n]++;
    }

    return pfs;
}

// <END-OF-CODE>
