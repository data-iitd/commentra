
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int even[2] = {0}, odd[2] = {0};
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            even[s[i] - '0']++;
        } else {
            odd[s[i] - '0']++;
        }
    }
    cout << min(s.length() - (even[0] + odd[1]), s.length() - (even[1] + odd[0])) << endl;
    return 0;
}

