
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> problems(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        problems[i] = l - 1 + r;
    }

    vector<int> cumsum(n + 1);
    partial_sum(problems.begin(), problems.end(), cumsum.begin() + 1);

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'A' && s[i] == 'C') {
            cumsum[i]++;
        }
    }

    partial_sum(cumsum.begin(), cumsum.end(), cumsum.begin());

    for (int i = 0; i < q; i++) {
        cout << cumsum[problems[i]] << endl;
    }

    return 0;
}

