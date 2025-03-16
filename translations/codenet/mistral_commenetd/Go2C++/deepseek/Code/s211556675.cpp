#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <complex>
#include <bitset>
#include <functional>
#include <chrono>
#include <random>
#include <cassert>

using namespace std;

class Scanner {
public:
    Scanner(istream &is) : sc(is) {
        sc.sync_with_stdio(false);
        sc.tie(nullptr);
    }

    string nextStr() {
        string s;
        sc >> s;
        return s;
    }

    int nextInt() {
        int i;
        sc >> i;
        return i;
    }

    double nextFloat() {
        double f;
        sc >> f;
        return f;
    }

    vector<int> nextInts(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            sc >> res[i];
        }
        return res;
    }

    vector<double> nextFloats(int n) {
        vector<double> res(n);
        for (int i = 0; i < n; i++) {
            sc >> res[i];
        }
        return res;
    }

private:
    istream &sc;
};

int max(const vector<int> &nums) {
    int m = nums[0];
    for (int i : nums) {
        if (m < i) {
            m = i;
        }
    }
    return m;
}

int min(const vector<int> &nums) {
    int m = nums[0];
    for (int i : nums) {
        if (m > i) {
            m = i;
        }
    }
    return m;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

struct Val {
    int id, num;
};

struct ByNum {
    bool operator()(const Val &a, const Val &b) const {
        return a.num < b.num;
    }
};

int main() {
    Scanner sc(cin);
    ostream &wtr = cout;

    int A = sc.nextInt(), B = sc.nextInt(), C = sc.nextInt(), K = sc.nextInt();

    int ma = max({A, B, C});

    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    int answer = pow(ma, K) + rest;

    wtr << answer << '\n';
    return 0;
}
