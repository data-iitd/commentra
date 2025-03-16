#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1000000007;
const int INF2 = 1000000009;
const int INF3 = 998244353;
bool DEBUG = false;

// IO helper functions
string nextToken() {
    string token;
    cin >> token;
    return token;
}

string nextLine() {
    string line;
    getline(cin, line);
    return line;
}

void setInteractive(istream& is, ostream& os) {
    cin.rdbuf(is.rdbuf());
    cout.rdbuf(os.rdbuf());
}

void setOutput(ostream& os) {
    cout.rdbuf(os.rdbuf());
}

void flush() {
    cout.flush();
}

bool isSpace(char c) {
    switch (c) {
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case ' ':
            return true;
        default:
            return false;
    }
}

bool isNewLine(char c) {
    switch (c) {
        case '\n':
        case '\r':
            return true;
        default:
            return false;
    }
}

void setInput(istream& is) {
    cin.rdbuf(is.rdbuf());
}

void setUnbufferedInput(istream& is) {
    cin.rdbuf(is.rdbuf());
}

char readc() {
    char c;
    cin >> c;
    return c;
}

string reads() {
    return nextToken();
}

string readsln() {
    return nextLine();
}

int readi() {
    return stoi(nextToken());
}

long long readll() {
    return stoll(nextToken());
}

double readf() {
    return stod(nextToken());
}

void printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void println(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

void eprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void eprintln(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
}

void debugf(const char* format, ...) {
    if (!DEBUG) {
        return;
    }
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void debug(const char* format, ...) {
    if (!DEBUG) {
        return;
    }
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    va_end(args);
}

// Utilities
int sumSlice(const vector<int>& a) {
    int res = 0;
    for (int v : a) {
        res += v;
    }
    return res;
}

long long sumSlicell(const vector<long long>& a) {
    long long res = 0;
    for (long long v : a) {
        res += v;
    }
    return res;
}

// Simple math functions
int min(int a, int b) {
    return a < b ? a : b;
}

long long minll(long long a, long long b) {
    return a < b ? a : b;
}

double minf(double a, double b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long maxll(long long a, long long b) {
    return a > b ? a : b;
}

double maxf(double a, double b) {
    return a > b ? a : b;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

long long absll(long long a) {
    return a < 0 ? -a : a;
}

double absf(double a) {
    return a < 0 ? -a : a;
}

// egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = gcd.
pair<int, pair<int, int>> egcd(int a, int b) {
    if (b == 0) {
        return {a, {1, 0}};
    }
    auto [d, x, y] = egcd(b, a % b);
    return {d, {y, x - a / b * y}};
}

pair<int, pair<int, int>> egcdll(int64_t a, int64_t b) {
    if (b == 0) {
        return {a, {1, 0}};
    }
    auto [d, x, y] = egcdll(b, a % b);
    return {d, {y, x - a / b * y}};
}

// gcd returns the greatest common divisor of two integers.
int gcd(int a, int b) {
    auto [d, _, _] = egcd(a, b);
    return d;
}

// gcdll returns the greatest common divisor of two int64.
int64_t gcdll(int64_t a, int64_t b) {
    auto [d, _, _] = egcdll(a, b);
    return d;
}

// Main function
int main() {
    setInteractive(cin, cout);

    int h = readi();
    int w = readi();
    int a = readi();
    vector<vector<int>> m(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        string s = reads();
        for (int j = 0; j < w; ++j) {
            m[i][j] = s[j];
        }
    }

    int answer = solve(h, w, a, m);
    println(answer);
    flush();
    return 0;
}

// Function to count the number of black cells in a grid.
int countBlack(int h, int w, const vector<vector<int>>& m) {
    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (m[i][j] == 'B') {
                ++count;
            }
        }
    }
    return count;
}

// Function to solve the problem.
int solve(int h, int w, int a, const vector<vector<int>>& m) {
    int result = 0;
    for (int i = 0; i < (1 << h); ++i) {
        for (int k = 0; k < (1 << w); ++k) {
            vector<vector<int>> tmp = m;
            for (int j = 0; j < h; ++j) {
                if (i & (1 << j)) {
                    for (int l = 0; l < w; ++l) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; ++j) {
                if (k & (1 << j)) {
                    for (int l = 0; l < h; ++l) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                ++result;
            }
        }
    }
    return result;
}
