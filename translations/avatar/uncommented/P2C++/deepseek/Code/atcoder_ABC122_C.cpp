#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

int count(int total, int i) {
    string s;
    cin >> s;
    if (s.substr(i - 1, 2) == "AC") {
        return total + 1;
    }
    return total;
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<int, int>> problems(q);
    for (int i = 0; i < q; ++i) {
        cin >> problems[i].first >> problems[i].second;
    }

    vector<int> cumsum(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        cumsum[i] = count(cumsum[i - 1], i);
    }

    for (const auto& p : problems) {
        int l = p.first;
        int r = p.second;
        cout << cumsum[r - 1] - cumsum[l - 1] << endl;
    }

    return 0;
}
