#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(2));

    for (int i = 0; i < n; ++i) {
        cin >> m[i][0] >> m[i][1];
    }

    sort(m.begin(), m.end(), greater<vector<int>>());

    vector<int> a = m[0];
    for (int i = 1; i < n; ++i) {
        if (m[i][1] > a[1]) {
            cout << "Happy Alex" << endl;
            return 0;
        }
        a = m[i];
    }

    cout << "Poor Alex" << endl;
    return 0;
}

// <END-OF-CODE>
