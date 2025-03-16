#include <iostream>
#include <iomanip>
#include <math.h>
#include <list>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
#include <map>
#include <string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include <stack>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;

// Function to compute the greatest common divisor (GCD) of two numbers
template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

// Function to compute the least common multiple (LCM) of two numbers
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

// Function to get the prime factorization of a number
template<typename T>
map<T, T> getPrimeFactor(T n) {
    map<T, T> res;
    // Iterate from 2 to the square root of n
    for (T i = 2; i * i <= n; ++i) {
        // While i divides n, store i in the result map
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    // If n is still greater than 1, it is a prime factor
    if (n != 1) res[n] = 1;
    return res;
}

// Function to check if a number is prime
template<typename T>
bool IsPrimeNumber(T num) {
    if (num <= 2) return true; // 0, 1, and 2 are considered prime
    else if (num % 2 == 0) return false; // Exclude even numbers

    double sqrtNum = sqrt(num);
    // Check for factors from 3 to the square root of num
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false; // Found a factor, not prime
        }
    }

    return true; // No factors found, num is prime
}

// Function to compute modular inverse using the Extended Euclidean Algorithm
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    // Loop until b becomes zero
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b); // Swap a and b
        u -= t * v; swap(u, v); // Update u and v
    }
    u %= m; // Ensure u is within the modulo
    if (u < 0) u += m; // Adjust if u is negative
    return u; // Return the modular inverse
}

// Macro definitions for loop iterations
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

int main() {
    ll N, K;
    // Input the number of elements and the value of K
    std::cin >> N >> K;

    vll A(N + 1);
    // Input the elements into the vector A
    repeq(i, 1, N) {
        std::cin >> A[i];
    }

    ll cur = 1; // Initialize current position
    vll dic(N + 1, -1); // Dictionary to store the first occurrence of each index
    bool flg = false; // Flag to indicate if we have entered a cycle

    // Process the sequence based on the value of K
    repeq(i, 1, K) {
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
            flg = true; // Set the flag indicating we are in a cycle
        }
    }

    // Output the final position after K steps
    std::cout << cur << endl;
    return 0; // End of the program
}
