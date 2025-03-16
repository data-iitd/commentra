#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    string s;
    for (int i = 0; i < N; i++) {
        s += to_string(i);
    }
    for (int i = 0; i < K; i++) {
        string tmp;
        for (int j = 0; j < N; j++) {
            tmp += s[j];
        }
        s = tmp;
    }
    cout << s.size() << endl;
}

