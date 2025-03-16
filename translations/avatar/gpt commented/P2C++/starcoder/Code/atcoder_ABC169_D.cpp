#include <bits/stdc++.h>
using namespace std;

// Function to read a single line of input
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read a list of integers from a single line of input
vector<int> get_nums_l() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] =='') continue;
        int num = 0;
        while (i < s.size() && s[i]!='') {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        v.push_back(num);
    }
    return v;
}

// Function to read 'n' integers from input, one per line
vector<int> get_nums_n(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    return v;
}

// Function to read all integers from standard input
vector<int> get_all_int() {
    vector<int> v;
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    return v;
}

// Generator function to yield elements from an iterable within a specified range
template<typename T>
T rangeI(T it, int l, int r) {
    for (int i = 0; i < l; i++) {
        it++;
    }
    for (int i = 0; i < r - l; i++) {
        yield *it;
        it++;
    }
}

// Debugging function to print debug messages to stderr
void log(string s) {
    cerr << s << endl;
}

// Define a large constant for infinity
const long long INF = 999999999999999999999999;

// Define a modulus constant for calculations
const long long MOD = 1000000007;

// Read an integer 'n' from input
int n = stoi(input());

// If n is 1, print 0 and exit
if (n == 1) {
    cout << 0 << endl;
    return 0;
}

// Function to perform prime factorization of a number
vector<int> prime_factorize(int n) {
    vector<int> a;
    // Divide n by 2 until it is odd
    while (n % 2 == 0) {
        a.push_back(2);
        n /= 2;
    }
    
    // Check for odd factors from 3 upwards
    int f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            a.push_back(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    
    // If n is still greater than 1, it is a prime factor
    if (n!= 1) {
        a.push_back(n);
    }
    
    return a;
}

// Perform prime factorization on n
vector<int> fac_ = prime_factorize(n);

// Count the occurrences of each prime factor
map<int, int> fac;
for (int p : fac_) {
    fac[p]++;
}

// Initialize the answer variable
long long ans = 0;

// Calculate the number of ways to express the prime factors
for (auto p : fac) {
    int x = p.second;
    // For each prime factor's exponent, calculate how many times it can be used
    for (int i = 1; i < 99999999; i++) {
        if (x >= i) {
            x -= i;
            ans += 1;
        } else {
            break;
        }
    }
}

// Print the final answer
cout << ans << endl;

// 