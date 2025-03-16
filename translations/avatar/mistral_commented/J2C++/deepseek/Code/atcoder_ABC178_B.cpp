#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class FastReader {
public:
    FastReader() {
        cin.tie(0);
        ios::sync_with_stdio(false);
    }

    string next() {
        string token;
        cin >> token;
        return token;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }

    string nextLine() {
        string line;
        getline(cin, line);
        return line;
    }
};

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

int main() {
    FastReader in;

    vector<long long> a(4);

    for (int i = 0; i < 4; i++) {
        a[i] = in.nextLong();
    }

    long long result = max({a[0] * a[2], a[1] * a[3], max(a[0] * a[3], a[1] * a[2])});

    cout << result << endl;

    return 0;
}

