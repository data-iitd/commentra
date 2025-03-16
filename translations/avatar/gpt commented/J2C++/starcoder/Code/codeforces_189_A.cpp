#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int dp[4010];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = a; j < 4010; j++) {
            dp[j] = max(dp[j], dp[j - a] + 1);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = b; j < 4010; j++) {
            dp[j] = max(dp[j], dp[j - b] + 1);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = c; j < 4010; j++) {
            dp[j] = max(dp[j], dp[j - c] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}

