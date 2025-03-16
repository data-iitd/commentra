#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<pair<int, int>> problems(q);
    for (auto& p : problems) {
        cin >> p.first >> p.second;
    }

    vector<int> cumsum(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        cumsum[i] = cumsum[i - 1] + (s.substr(i - 1, 2) == "AC");
    }

    for (const auto& p : problems) {
        int l = p.first;
        int r = p.second;
        cout << cumsum[r - 1] - cumsum[l - 1] << endl;
    }

    return 0;
}
