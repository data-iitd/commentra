#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// I/O
class Scanner {
public:
    Scanner(istream& is) : is(is) {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
    }

    string nextStr() {
        string line;
        getline(is, line);
        return line;
    }

    int nextInt() {
        int num;
        is >> num;
        return num;
    }

    double nextDouble() {
        double num;
        is >> num;
        return num;
    }

    vector<int> nextInts(int n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            is >> nums[i];
        }
        return nums;
    }

    vector<double> nextDoubles(int n) {
        vector<double> nums(n);
        for (int i = 0; i < n; ++i) {
            is >> nums[i];
        }
        return nums;
    }

private:
    istream& is;
};

// Arithmetic
int max(const vector<int>& nums) {
    int m = nums[0];
    for (int num : nums) {
        if (m < num) {
            m = num;
        }
    }
    return m;
}

int min(const vector<int>& nums) {
    int m = nums[0];
    for (int num : nums) {
        if (m > num) {
            m = num;
        }
    }
    return m;
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; ++i) {
        res *= x;
    }
    return res;
}

// Sort
struct Val {
    int id, num;
};

bool byNum(const Val& a, const Val& b) {
    return a.num < b.num;
}

int main() {
    Scanner sc(cin);
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

    for (int i = 1; i <= K; ++i) {
        ma *= 2;
    }

    cout << ma + rest << '\n';
    return 0;
}
