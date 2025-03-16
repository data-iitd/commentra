#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<vector<int>> problems(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> problems[i][0] >> problems[i][1];
    }

    vector<int> cumsum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i - 1] + (s[i - 1] == 'A' && s[i] == 'C');
    }

    for (auto problem : problems) {
        cout << cumsum[problem[1] - 1] - cumsum[problem[0] - 1] << '\n';
    }

    return 0;
}

