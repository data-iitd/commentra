#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

// Function to read an integer from input
int getInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read a string from input
string getString() {
    string s;
    cin >> s;
    return s;
}

// Function to return the absolute value of an integer
int abs(int a) {
    return abs(a);
}

// Function to compute p raised to the power of q
int pow(int p, int q) {
    return pow(p, q);
}

// Function to compute (n^p) % mod using exponentiation by squaring
int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % MOD;
    } else {
        return (n * powMod(n, p - 1)) % MOD;
    }
}

// Function to find the minimum value among a variable number of integers
int min(int a, int b) {
    return min(a, b);
}

// Function to find the maximum value among a variable number of integers
int max(int a, int b) {
    return max(a, b);
}

// Function to check if a string exists in a slice of strings
bool strSearch(vector<string> &a, string &b) {
    for (auto &s : a) {
        if (s == b) {
            return true;
        }
    }
    return false;
}

// Function to print an integer array in a formatted way
void printIntArray(vector<int> &array) {
    cout << "[";
    for (size_t i = 0; i < array.size(); ++i) {
        cout << array[i];
        if (i < array.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Function to calculate x % mod
int calcMod(int x) {
    return x % MOD;
}

// Function to reverse a string
string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    // Check for factors from 3 to the square root of n
    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int N = getInt();
    int sqrtN = sqrt(N);

    int minVal = N;
    for (int i = 1; i <= sqrtN; i++) {
        if (N % i != 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        if (num < minVal) {
            minVal = num;
        }
    }

    cout << minVal << endl;

    return 0;
}
