#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> l(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (l[i][j] == '.') {
                if ((i + j) % 2) {
                    l[i][j] = 'W';
                } else {
                    l[i][j] = 'B';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << l[i][j];
        }
        cout << endl;
    }

    return 0;
}
