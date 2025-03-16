
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Define a constant for the modulo value
    const long long mod = 1000000007;

    int n, q;
    string c;
    cin >> n >> q >> c;

    vector<vector<int>> range(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> range[i][0] >> range[i][1];
    }

    vector<int> frag(n + 1);
    vector<int> rui(n + 1);

    for (int i = 2; i <= n; i++) {
        if (c[i - 2] == 'A' && c[i - 1] == 'C') {
            frag[i]++;
        }
        rui[i] = rui[i - 1] + frag[i];
    }

    for (int i = 0; i < q; i++) {
        int left = range[i][0];
        int right = range[i][1];
        cout << rui[right] - rui[left] << endl;
    }

    return 0;
}

