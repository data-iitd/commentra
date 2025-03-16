#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int gcd = gcd(n, m);
    string s, t;
    cin >> s >> t;
    vector<long long> differences;
    for (int k = 0; k < gcd; ++k) {
        if (s[k * n / gcd] != t[k * m / gcd]) {
            differences.push_back(k);
        }
    }
    if (!differences.empty()) {
        cout << -1 << endl;
    } else {
        long long lcm = static_cast<long long>(n) * m / gcd;
        cout << lcm << endl;
    }
    return 0;
}
