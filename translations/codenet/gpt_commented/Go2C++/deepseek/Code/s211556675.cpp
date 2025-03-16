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
    Scanner(istream& is) : is_(is) {
        is_.sync_with_stdio(false);
        cin.tie(nullptr);
    }

    string next() {
        string line;
        getline(is_, line);
        return line;
    }

    int nextInt() {
        int num;
        is_ >> num;
        return num;
    }

    double nextDouble() {
        double num;
        is_ >> num;
        return num;
    }

    vector<int> nextInts(int n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            is_ >> nums[i];
        }
        return nums;
    }

    vector<double> nextDoubles(int n) {
        vector<double> nums(n);
        for (int i = 0; i < n; ++i) {
            is_ >> nums[i];
        }
        return nums;
    }

private:
    istream& is_;
};

// Arithmetic functions

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

// Sort related types and methods

struct Val {
    int id, num;
};

class ByNum {
public:
    ByNum(const vector<Val>& vals) : vals_(vals) {}

    size_t size() const { return vals_.size(); }

    Val operator[](size_t index) const { return vals_[index]; }

    bool operator<(const ByNum& other) const {
        return vals_[0].num < other.vals_[0].num;
    }

private:
    const vector<Val>& vals_;
};

// Main function
int main() {
    Scanner sc(cin);

    // Read four integers from input
    int A = sc.nextInt();
    int B = sc.nextInt();
    int C = sc.nextInt();
    int K = sc.nextInt();

    // Determine the maximum value among A, B, and C
    int ma = max({A, B, C});
    int rest = 0; // Initialize the rest variable to hold the sum of the other two values

    // Calculate the sum of the two smaller values
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    // Double the maximum value K times
    for (int i = 1; i <= K; ++i) {
        ma *= 2;
    }

    // Output the final result: doubled max value plus the sum of the other two
    cout << ma + rest << '\n';

    return 0;
}
