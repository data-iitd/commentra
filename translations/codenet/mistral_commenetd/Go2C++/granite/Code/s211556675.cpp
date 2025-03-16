

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Scanner {
    Scanner() : sc(cin) {
        sc.imbue(locale(""));
        sc.exceptions(ios::badbit | ios::failbit);
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

    float nextFloat() {
        float f;
        sc >> f;
        return f;
    }

    vector<rune> nextRuneSlice() {
        string s = nextStr();
        return vector<rune>(s.begin(), s.end());
    }

    vector<int> nextIntSlice(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    vector<float> nextFloatSlice(int n) {
        vector<float> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextFloat();
        }
        return res;
    }

private:
    istream& sc;
};

int max(vector<int> nums) {
    int m = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (m < nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int min(vector<int> nums) {
    int m = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (m > nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int abs(int x) {
    if (x > 0) {
        return x;
    }
    return -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int main() {
    Scanner sc;
    ofstream wtr("output.txt");

    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int K = sc.nextInt();

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

    wtr << answer << endl;
    wtr.close();

    return 0;
}

