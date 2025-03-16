#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    int n;
    cin >> n;
    int beacon[1000001];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int b;
        cin >> b;
        beacon[a] = b;
    }
    int dp[1000001];
    if (beacon[0]!= 0)
        dp[0] = 1;
    for (int i = 1; i < 1000001; i++) {
        if (beacon[i]!= 0 && beacon[i] < i) {
            dp[i] = dp[i - beacon[i] - 1] + 1;
        } else if (beacon[i]!= 0) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    int max = 0;
    for (int i = 0; i < 1000001; i++) {
        max = max > dp[i]? max : dp[i];
    }
    cout << n - max << "\n";
    return 0;
}

