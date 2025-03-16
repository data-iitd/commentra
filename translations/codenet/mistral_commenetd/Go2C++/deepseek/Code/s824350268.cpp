#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Constants definition
const long long initialBufSize = 10000;
const long long maxBufSize = 1000000;
const long long mod = 1e9 + 7;

// Helper functions for reading integers and strings from the standard input
int getInt() {
    int i;
    cin >> i;
    return i;
}

string getString() {
    string s;
    cin >> s;
    return s;
}

// Helper functions for basic arithmetic operations
int abs(int a) {
    return abs(a);
}

int pow(int p, int q) {
    return pow(p, q);
}

int powMod(int n, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        int t = powMod(n, p / 2);
        return (t * t) % mod;
    } else {
        return (n * powMod(n, p - 1)) % mod;
    }
}

// Helper functions for finding the minimum and maximum values
int min(vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Function min() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = min(res, num);
    }
    return res;
}

int max(vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Function max() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = max(res, num);
    }
    return res;
}

// Helper function for searching a string in an array of strings
bool strSearch(vector<string>& a, string b) {
    for (string s : a) {
        if (s == b) {
            return true;
        }
    }
    return false;
}

// Helper function for printing an integer array
void printIntArray(vector<int>& array) {
    for (int i = 0; i < array.size(); ++i) {
        if (i > 0) cout << " ";
        cout << array[i];
    }
    cout << endl;
}

// Helper function for calculating the modulo operation
int calcMod(int x) {
    return x % mod;
}

// Helper function for reversing a string
string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Helper function for checking if a number is prime
bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    int sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Read the first integer from the standard input
    int N = getInt();

    // Calculate the square root of N
    int sqrtN = sqrt(N);

    // Initialize the minimum number with N
    int min = N;

    // Iterate through all numbers from 1 to the square root of N
    for (int i = 1; i <= sqrtN; i++) {
        // Check if N is divisible by i
        if (N % i != 0) {
            continue;
        }

        // Calculate the number of divisors of i and N
        int num = i + (N / i) - 2;

        // Update the minimum number if the current number is smaller
        if (num < min) {
            min = num;
        }
    }

    // Print the minimum number
    cout << min << endl;

    return 0;
}
