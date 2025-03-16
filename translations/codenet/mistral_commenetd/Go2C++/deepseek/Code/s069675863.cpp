#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 (int64_t)1 << 60
#define INF_INT32 (int32_t)1 << 30
#define NIL -1

vector<rune> S;
int x, y;

vector<vector<bool>> dpx, dpy;

void init() {
    // bufio.ScanWords <---> bufio.ScanLines
    auto readString = []() -> string {
        string str;
        cin >> str;
        return str;
    };
    auto readInt = []() -> int {
        return stoi(readString());
    };
    auto readInt2 = []() -> pair<int, int> {
        int a, b;
        cin >> a >> b;
        return {a, b};
    };
    auto readIntSlice = [](int n) -> vector<int> {
        vector<int> X(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        return X;
    };
    auto readInt64 = []() -> int64_t {
        int64_t i;
        cin >> i;
        return i;
    };
    auto readInt64Slice = [](int n) -> vector<int64_t> {
        vector<int64_t> X(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        return X;
    };
    auto readFloat64 = []() -> double {
        double f;
        cin >> f;
        return f;
    };
    auto readFloat64Slice = [](int n) -> vector<double> {
        vector<double> X(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i];
        }
        return X;
    };
    auto readRuneSlice = []() -> vector<rune> {
        string str;
        cin >> str;
        vector<rune> S(str.begin(), str.end());
        return S;
    };
}

void make2DBooleanArray(int rows, int cols) {
    dpx.resize(rows, vector<bool>(cols, false));
    dpy.resize(rows, vector<bool>(cols, false));
}

void updateDPX(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
        }
        if (j - val >= 2000 && index != 0) {
            dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
        }
    }
}

void updateDPY(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
        }
        if (j - val >= 2000) {
            dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
        }
    }
}

int main() {
    init();
    S = readRuneSlice();
    tie(x, y) = readInt2();
    make2DBooleanArray(8000, 20000);

    vector<int> evens, odds;
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0) {
            evens.push_back(i);
        } else {
            odds.push_back(i);
        }
    }

    dpx[0][10000] = true;
    for (int i = 0; i < evens.size(); i++) {
        updateDPX(i, evens[i]);
    }

    dpy[0][10000] = true;
    for (int i = 0; i < odds.size(); i++) {
        updateDPY(i, odds[i]);
    }

    if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
