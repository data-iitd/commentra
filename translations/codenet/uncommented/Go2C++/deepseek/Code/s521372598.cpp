#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int getInt() {
    int ret;
    cin >> ret;
    return ret;
}

vector<int> getIntSlice(int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
        cin >> ret[i];
    }
    return ret;
}

string getString() {
    string ret;
    cin >> ret;
    return ret;
}

vector<int> getRunes() {
    string str = getString();
    vector<int> ret(str.size());
    for (size_t i = 0; i < str.size(); ++i) {
        ret[i] = str[i];
    }
    return ret;
}

void solve() {
    int n = getInt();
    vector<int> as = getIntSlice(n);

    vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
        xs[i] = as[i] - i + 1;
    }
    sort(xs.begin(), xs.end());

    int b = xs[n / 2];
    int ans = 0;
    for (int x : xs) {
        ans += abs(x - b);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

