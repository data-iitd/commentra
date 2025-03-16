
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i][0] == 'M') {
            for (int j = 0; j < n; j++) {
                if (s[j][0] == 'A') {
                    for (int k = 0; k < n; k++) {
                        if (s[k][0] == 'R') {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
