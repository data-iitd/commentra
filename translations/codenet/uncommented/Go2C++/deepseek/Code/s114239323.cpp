#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int nextInt() {
    int v;
    cin >> v;
    return v;
}

vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    return r;
}

int Max(const vector<int>& a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

int Min(const vector<int>& a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

int Sum(const vector<int>& a) {
    int r = 0;
    for (int i : a) {
        r += i;
    }
    return r;
}

int Abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int main() {
    int N = nextInt();
    vector<int> h = nextInts(N);

    vector<int> dp(N, 0);
    dp[1] = Abs(h[0] - h[1]);

    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + Abs(h[i] - h[i - 1]), dp[i - 2] + Abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}

