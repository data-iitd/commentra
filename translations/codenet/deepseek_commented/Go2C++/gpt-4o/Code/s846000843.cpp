#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

class Io {
public:
    Io() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }

    int Int() {
        int x;
        cin >> x;
        return x;
    }

    void PrintLn(int x) {
        cout << x << "\n";
    }
};

vector<int> CumSum(const vector<int>& nums) {
    vector<int> sums = {0};
    for (int num : nums) {
        sums.push_back(sums.back() + num);
    }
    return sums;
}

int Abs(int a) {
    return a >= 0 ? a : -a;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    Io io;

    int n = io.Int(); // Read the number of integers.
    vector<int> aa(n);

    for (int i = 0; i < n; i++) {
        aa[i] = io.Int(); // Read each integer and store it in the vector.
    }

    vector<int> cumsum = CumSum(aa); // Compute the cumulative sum of the integers.

    int ans = numeric_limits<int>::max();
    for (int i = 1; i < cumsum.size() - 1; i++) {
        ans = Min(ans, Abs(cumsum.back() - cumsum[i] - (cumsum[i] - cumsum[0])));
    }

    io.PrintLn(ans); // Print the minimum absolute difference.

    return 0;
}

// <END-OF-CODE>
