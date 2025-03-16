
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// I/O
class Scanner {
private:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
public:
    Scanner() {
    }

    string nextStr() {
        string str;
        cin >> str;
        return str;
    }

    int nextInt() {
        int num;
        cin >> num;
        return num;
    }

    long long nextLong() {
        long long num;
        cin >> num;
        return num;
    }

    double nextDouble() {
        double num;
        cin >> num;
        return num;
    }

    vector<string> nextStrSlice(int n) {
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }
        return strs;
    }

    vector<int> nextIntSlice(int n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        return nums;
    }

    vector<long long> nextLongSlice(int n) {
        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        return nums;
    }

    vector<double> nextDoubleSlice(int n) {
        vector<double> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        return nums;
    }
};

// Arithmetic
int max(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
        if (m < nums[i]) {
            m = nums[i];
        }
    }
    return m;
}

int min(int nums[], int n) {
    int m = nums[0];
    for (int i = 1; i < n; i++) {
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

// Sort
struct Val {
    int id, num;
};

bool cmp(Val a, Val b) {
    return a.num < b.num;
}

// Main
int main() {
    Scanner sc;
    int A, B, C, K;
    A = sc.nextInt();
    B = sc.nextInt();
    C = sc.nextInt();
    K = sc.nextInt();

    int ma = max(A, B, C);
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }

    cout << ma + rest << endl;

    return 0;
}

