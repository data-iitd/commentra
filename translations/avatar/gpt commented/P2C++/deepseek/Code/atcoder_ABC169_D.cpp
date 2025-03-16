#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <functional>
#include <algorithm>
#include <limits.h>

using namespace std;

// Function to read a single line of input
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read a list of integers from a single line of input
vector<int> get_nums_l() {
    string line = input();
    vector<int> nums;
    string num_str;
    for (char c : line) {
        if (c == ' ') {
            nums.push_back(stoi(num_str));
            num_str.clear();
        } else {
            num_str += c;
        }
    }
    if (!num_str.empty()) {
        nums.push_back(stoi(num_str));
    }
    return nums;
}

// Function to read 'n' integers from input, one per line
vector<int> get_nums_n(int n) {
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    return nums;
}

// Function to read all integers from standard input
vector<int> get_all_int() {
    string all_input;
    getline(cin, all_input);
    vector<int> nums;
    string num_str;
    for (char c : all_input) {
        if (c == ' ') {
            nums.push_back(stoi(num_str));
            num_str.clear();
        } else {
            num_str += c;
        }
    }
    if (!num_str.empty()) {
        nums.push_back(stoi(num_str));
    }
    return nums;
}

// Generator function to yield elements from an iterable within a specified range
template<typename T>
class RangeI {
public:
    RangeI(const T& it, int l, int r) : it_(it), l_(l), r_(r), index_(0) {}

    class iterator {
    public:
        iterator(const RangeI& range, int index) : range_(range), index_(index) {}

        bool operator!=(const iterator& other) const {
            return index_ != other.index_;
        }

        void operator++() {
            ++index_;
        }

        const T& operator*() const {
            return range_.it_[index_];
        }

    private:
        const RangeI& range_;
        int index_;
    };

    iterator begin() const {
        return iterator(*this, l_);
    }

    iterator end() const {
        return iterator(*this, r_);
    }

private:
    const T& it_;
    int l_, r_, index_;
};

// Debugging function to print debug messages to stderr
void log(const vector<int>& args) {
    for (int arg : args) {
        cerr << "DEBUG: " << arg << " ";
    }
    cerr << endl;
}

// Define a large constant for infinity
const long long INF = 999999999999999999;

// Define a modulus constant for calculations
const int MOD = 1000000007;

// Read an integer 'n' from input
int n;
cin >> n;

// If n is 1, print 0 and exit
if (n == 1) {
    cout << 0 << endl;
    return 0;
}

// Function to perform prime factorization of a number
vector<int> prime_factorize(int n) {
    vector<int> factors;
    // Divide n by 2 until it is odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for odd factors from 3 upwards
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still greater than 1, it is a prime factor
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

// Perform prime factorization on n
vector<int> factors = prime_factorize(n);

// Count the occurrences of each prime factor
unordered_map<int, int> factor_count;
for (int factor : factors) {
    factor_count[factor]++;
}

// Initialize the answer variable
int ans = 0;

// Calculate the number of ways to express the prime factors
for (const auto& pair : factor_count) {
    int p = pair.first;
    int e = pair.second;
    int x = e;
    // For each prime factor's exponent, calculate how many times it can be used
    for (int i = 1; ; ++i) {
        if (x >= i) {
            x -= i;
            ans++;
        } else {
            break;
        }
    }
}

// Print the final answer
cout << ans << endl;

