#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<int> getNextInts(istream &is) {
    string line;
    getline(is, line);
    vector<string> parts = split(line, ' ');
    vector<int> result;
    for (const string &part : parts) {
        result.push_back(stoi(part));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> mm(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i) {
        cin >> mm[i] >> mm[i + 1];
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; ++k) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}
