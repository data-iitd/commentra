#include <iostream>
#include <vector>

using namespace std;

void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> count(n, vector<int>(n, 0));
    int ans = -1;

    for (int k = 0; k < m; k++) {
        int x, y;
        cin >> x >> y;
        x -= 1; // Convert to 0-based index
        y -= 1; // Convert to 0-based index
        bool found = false;

        for (int i = x - 2; i <= x; i++) {
            for (int j = y - 2; j <= y; j++) {
                if (i >= 0 && i < n && j >= 0 && j < n) {
                    count[i][j] += 1;
                    if (count[i][j] == 9) {
                        found = true;
                    }
                }
            }
        }
        if (found) {
            ans = k + 1; // Store the 1-based index of the found case
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    solve_case();
    return 0;
}

// <END-OF-CODE>
