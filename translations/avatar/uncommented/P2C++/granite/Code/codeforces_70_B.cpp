
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    regex re("[.?!]");
    int ans = 1, sumL = 0;
    for (auto it = sre.begin(); it!= sre.end(); ++it) {
        string t = *it;
        t += '.';
        int L = t.length();
        if (L > 1) {
            if (L > n) {
                cout << "Impossible" << endl;
                return 0;
            }
            if (sumL + L + (sumL > 0) > n) {
                ans++;
                sumL = L;
            } else {
                sumL = sumL + L + (sumL > 0);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
