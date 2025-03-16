
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    regex r("[.?!]");
    int ans = 1, sumL = 0;
    for (auto i = sregex_token_iterator(s.begin(), s.end(), r, -1); i != sregex_token_iterator(); i++) {
        string s = (*i).str();
        s = s.substr(0, s.size() - 1) + ".";
        int L = s.size();
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

