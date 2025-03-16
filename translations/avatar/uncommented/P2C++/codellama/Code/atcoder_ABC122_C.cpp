#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> problems(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        problems[i] = r - l + 1;
    }
    vector<int> cumsum(n + 1);
    for (int i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i - 1] + (s[i - 1] == 'A' && s[i] == 'C');
    }
    for (int i = 0; i < q; i++) {
        cout << cumsum[problems[i]] - cumsum[problems[i] - 1] << endl;
    }
    return 0;
}

