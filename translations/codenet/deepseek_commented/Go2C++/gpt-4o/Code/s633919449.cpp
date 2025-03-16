#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>

const int mod = 1e9 + 7;

// Function to read an integer from standard input
int getInt() {
    int x;
    std::cin >> x;
    return x;
}

// Function to read an array of integers from standard input
std::vector<int> getIntArray(int n) {
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        array[i] = getInt();
    }
    return array;
}

// Function to calculate the absolute value
int abs(int a) {
    return std::abs(a);
}

// Function to calculate power
int pow(int p, int q) {
    return static_cast<int>(std::pow(p, q));
}

// Function to calculate power modulo
int powMod(int n, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return t * t % mod;
    } else {
        return n * powMod(n, p - 1) % mod;
    }
}

// Function to find the minimum of a list of integers
int min(std::initializer_list<int> nums) {
    return *std::min_element(nums);
}

// Function to find the maximum of a list of integers
int max(std::initializer_list<int> nums) {
    return *std::max_element(nums);
}

// Function to check if a string exists in a vector of strings
bool strSearch(const std::vector<std::string>& a, const std::string& b) {
    return std::find(a.begin(), a.end(), b) != a.end();
}

// Function to print an array of integers
void printIntArray(const std::vector<int>& array) {
    std::cout << "[";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i];
        if (i < array.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Function to calculate gcd
int calcGcd(int x, int y) {
    return y == 0 ? x : calcGcd(y, x % y);
}

// Function to get divisors of a number
std::vector<int> getDivisor(int n) {
    std::unordered_set<int> divisor;
    divisor.insert(1);
    if (n != 1) divisor.insert(n);

    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }

    return std::vector<int>(divisor.begin(), divisor.end());
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to reverse a string
std::string reverse(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

// Main function
int main() {
    int N = getInt();

    switch (N % 10) {
        case 2: case 4: case 5: case 7: case 9:
            std::cout << "hon" << std::endl;
            break;
        case 0: case 1: case 6: case 8:
            std::cout << "pon" << std::endl;
            break;
        case 3:
            std::cout << "bon" << std::endl;
            break;
    }

    return 0;
}

// <END-OF-CODE>
