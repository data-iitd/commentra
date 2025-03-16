
#include <bits/stdc++.h>
using namespace std;

// out is a utility function for printing output, currently commented out.
void out(vector<string> x) {
    // cout << x << endl;
}

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    out(s);
    sort(s.begin(), s.end());
    out(s);
    string ans = "";
    for (int i = 0; i < N; i++) {
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}

