#include <bits/stdc++.h>
using namespace std;

// FastReader class to read input efficiently
class FastReader {
    public:
        FastReader() {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
        }
        template <typename T>
        T next() {
            T x;
            cin >> x;
            return x;
        }
};

// Function to calculate x^y mod mod using efficient exponentiation by squaring
int modPower(int x, int y, int mod) {
    int res = 1;
    x %= mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

// Generic pair class to hold two elements of type T1 and T2
template <typename T1, typename T2>
class pair {
    public:
        T1 first;
        T2 second;
        pair(T1 first, T2 second) {
            this->first = first;
            this->second = second;
        }
};

// Main function to read input, calculate the maximum product, and print the result
int main() {
    FastReader in;
    long long a[4];
    for (int i = 0; i < 4; i++)
        a[i] = in.next<long long>();
    cout << max({a[0] * a[2], a[1] * a[3], max(a[0] * a[3], a[1] * a[2])});
    return 0;
}
