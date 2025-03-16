#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

class Main {
public:
    void run() {
        string cs;
        cin >> cs;
        vector<vector<long long>> dp(cs.size(), vector<long long>(13, 0));
        int base = 1;

        for (int i = 0; i < cs.size(); ++i) {
            if (cs[cs.size() - 1 - i] == '?') {
                for (int pre = 0; pre < 13; ++pre) {
                    for (int next = 0; next < 10; ++next) {
                        dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                        dp[i][(base * next + pre) % 13] %= MOD;
                    }
                }
            } else {
                int next = cs[cs.size() - 1 - i] - '0';
                for (int pre = 0; pre < 13; ++pre) {
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
            base = base * 10 % 13;
        }

        cout << dp[dp.size() - 1][5] << endl;
    }
};

int main() {
    Main().run();
    return 0;
}

