#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int pattern1(const vector<int>& l) {
    return (l[0] * l[3]) + (l[1] * l[4]);
}

int pattern2(const vector<int>& l) {
    return 2 * l[2] * max(l[3], l[4]);
}

int pattern3(const vector<int>& l) {
    return 2 * l[2] * min(l[3], l[4]) + doch(l);
}

int min(const vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Function min() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = min(res, num);
    }
    return res;
}

int max(const vector<int>& nums) {
    if (nums.empty()) {
        throw invalid_argument("Function max() requires at least one argument.");
    }
    int res = nums[0];
    for (int num : nums) {
        res = max(res, num);
    }
    return res;
}

int doch(const vector<int>& l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

int main() {
    vector<int> l(5);
    for (int i = 0; i < 5; ++i) {
        cin >> l[i];
    }
    cout << min({pattern1(l), pattern2(l), pattern3(l)}) << endl;
    return 0;
}
