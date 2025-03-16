
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
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
        cumsum[i] = cumsum[i - 1] + (s.substr(i - 1, 3) == "AC"? 1 : 0);
    }
    for (int i = 0; i < q; i++) {
        cout << cumsum[problems[i][1]] - cumsum[problems[i][0] - 1] << endl;
    }
    return 0;
}

