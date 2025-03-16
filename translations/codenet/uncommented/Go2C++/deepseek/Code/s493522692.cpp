#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <sstream>
#include <queue>

using namespace std;

// Util
string nextStr() {
    string s;
    cin >> s;
    return s;
}

int nextInt() {
    int i;
    cin >> i;
    return i;
}

int maxInt(int a, int b) {
    return a > b ? a : b;
}

int minInt(int a, int b) {
    return a < b ? a : b;
}

int absInt(int a) {
    return a >= 0 ? a : -a;
}

double absFloat64(double a) {
    return a >= 0 ? a : -a;
}

double maxFloat64(double a, double b) {
    return a > b ? a : b;
}

double minFloat64(double a, double b) {
    return a < b ? a : b;
}

int str2Int(string s) {
    return stoi(s);
}

string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int powInt(int p, int q) {
    return (int)pow(p, q);
}

bool isPrime(int x) {
    if (x == 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    bool b = true;
    int rootx = (int)sqrt(x);
    for (int i = 3; i <= rootx; i += 2) {
        if (x % i == 0) {
            b = false;
            break;
        }
    }
    return b;
}

vector<int> PrimeFactors(int n) {
    vector<int> pfs;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs.push_back(2);
        n /= 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i += 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs.push_back(i);
            n /= i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        pfs.push_back(n);
    }

    return pfs;
}

unordered_map<int, int> PrimeFactorsMap(int n) {
    unordered_map<int, int> pfs;
    // Get the number of 2s that divide n
    while (n % 2 == 0) {
        pfs[2]++;
        n /= 2;
    }

    // n must be odd at this point. so we can skip one element
    // (note i = i + 2)
    for (int i = 3; i * i <= n; i += 2) {
        // while i divides n, append i and divide n
        while (n % i == 0) {
            pfs[i]++;
            n /= i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (n > 2) {
        pfs[n]++;
    }

    return pfs;
}

int sumInts(vector<int>& x) {
    int total = 0;
    for (int v : x) {
        total += v;
    }
    return total;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

// Main
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = nextInt();
    int M = nextInt();
    int tmp = minInt(N, M / 2);
    int ans = tmp;
    N -= tmp;
    M -= tmp * 2;
    ans += M / 4;
    cout << ans << '\n';

    return 0;
}
