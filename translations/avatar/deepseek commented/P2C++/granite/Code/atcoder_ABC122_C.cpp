

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> cumsum(n+1);
    for (int i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i-1] + (s.substr(i-1, 3) == "AC"? 1 : 0);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << cumsum[r] - cumsum[l-1] << endl;
    }

    return 0;
}
