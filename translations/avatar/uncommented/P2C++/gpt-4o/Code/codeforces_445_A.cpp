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
                if ((i + j) % 2 == 1) 
                    s[j] = 'W';
                else 
                    s[j] = 'B';
            }
        }
        l[i] = s;
    }

    for (const auto& c : l) {
        cout << string(c.begin(), c.end()) << endl;
    }

    return 0;
}

// <END-OF-CODE>
