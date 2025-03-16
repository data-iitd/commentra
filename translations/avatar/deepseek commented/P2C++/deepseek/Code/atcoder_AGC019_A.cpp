#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <unordered_map>
#include <iomanip>

using namespace std;

#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define endl '\n'

const int INF = 1e18;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int ceil(int a, int b = 1) {
    return (a + b - 1) / b;
}

int round(int x) {
    return (x * 2 + 1) / 2;
}

int fermat(int x, int y, int MOD) {
    return x * pow(y, MOD - 2, MOD) % MOD;
}

int lcm_list(vector<int>& nums) {
    int result = 1;
    for (int num : nums) {
        result = lcm(result, num);
    }
    return result;
}

int INT() {
    int x;
    cin >> x;
    return x;
}

vector<int> MAP() {
    vector<int> nums(4);
    for (int i = 0; i < 4; ++i) {
        cin >> nums[i];
    }
    return nums;
}

vector<int> LIST() {
    vector<int> nums;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        nums.pb(num);
    }
    return nums;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> qhd = MAP();
    int n = INT();

    int best1L = min({qhd[0] * 4, qhd[1] * 2, qhd[2]});
    int best2L = min(qhd[3], best1L * 2);

    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;
    } else {
        cout << best2L * (n / 2) + best1L << endl;
    }

    return 0;
}
