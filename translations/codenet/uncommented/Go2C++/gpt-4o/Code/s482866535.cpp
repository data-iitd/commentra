#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream fp;
    if (argc > 1) {
        fp.open(argv[1]);
    } else {
        fp.open("/dev/stdin");
    }

    int n;
    fp >> n;

    vector<int> mm(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        fp >> mm[i];
        fp >> mm[i + 1];
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = numeric_limits<int>::max(); // Initialize to a large value
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
// <END-OF-CODE>
