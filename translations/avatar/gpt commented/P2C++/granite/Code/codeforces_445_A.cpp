
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> l(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                l[i][j] = (i + j) % 2 == 0? 'B' : 'W';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << l[i][j];
        }
        cout << endl;
    }

    return 0;
}
