#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int count(int total, const string& s, int i) {
    return (s.substr(i - 1, 2) == "AC") ? total + 1 : total;
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

    vector<int> cumsum(n);
    cumsum[0] = 0; // Initialize the first element
    for (int i = 1; i < n; ++i) {
        cumsum[i] = count(cumsum[i - 1], s, i);
    }

    for (const auto& p : problems) {
        int l = p.first, r = p.second;
        cout << cumsum[r - 1] - cumsum[l - 1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
