#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// out is a utility function to print multiple values with a newline.
void out(const vector<string>& x) {
    for (const auto& item : x) {
        cout << item;
    }
    cout << endl;
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

    string ans;
    for (const auto& item : s) {
        ans += item;
    }
    cout << ans << endl;

    return 0;
}
