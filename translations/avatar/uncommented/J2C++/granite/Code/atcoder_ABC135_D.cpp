
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MOD 100000007

int main() {
    string s;
    cin >> s;
    vector<vector<long long>> dp(s.size(), vector<long long>(13, 0));
    int base = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '?') {
            for (int pre = 0; pre < 13; pre++) {
                for (int next = 0; next < 10; next++) {
                    dp[i][(base * next + pre) % 13] += (i < s.size() - 1? dp[i + 1][pre] : (pre == 0? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            int next = s[i] - '0';
            for (int pre = 0; pre < 13; pre++) {
                dp[i][(base * next + pre) % 13] += (i < s.size() - 1? dp[i + 1][pre] : (pre == 0? 1 : 0));
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        base = base * 10 % 13;
    }
    cout << dp[0][5] << endl;
    return 0;
}
// END-OF-CODE