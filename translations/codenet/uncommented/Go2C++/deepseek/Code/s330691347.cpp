#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> s(N);

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    string ans = "";
    for (int i = 0; i < N; i++) {
        ans += s[i];
    }
    cout << ans << endl;

    return 0;
}
