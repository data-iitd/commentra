#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int Abs(int a) {
    return a < 0 ? -a : a;
}

int Min(const vector<int>& a) {
    return *min_element(a.begin(), a.end());
}

int main() {
    int N;
    cin >> N;
    
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    
    vector<int> dp(N, 0);
    dp[1] = Abs(h[0] - h[1]);
    
    for (int i = 2; i < N; i++) {
        dp[i] = Min({dp[i - 1] + Abs(h[i] - h[i - 1]),
                      dp[i - 2] + Abs(h[i] - h[i - 2])});
    }
    
    cout << dp[N - 1] << endl;
    return 0;
}

/* <END-OF-CODE> */
