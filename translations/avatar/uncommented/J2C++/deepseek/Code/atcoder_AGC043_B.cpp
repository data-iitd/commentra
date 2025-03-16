#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Main {
private:
    int cal(const string& s, char c) {
        int n = s.length();
        int m = n - 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c && (m & i) == i) {
                ans ^= 1;
            }
        }
        return ans;
    }

    void solve() {
        int n;
        string s;
        cin >> n >> s;
        stringstream sb;
        for (int i = 1; i < n; i++) {
            sb << abs(s[i] - s[i - 1]);
        }
        if (n == 2) {
            cout << sb.str()[0] << endl;
            return;
        }
        string s_new = sb.str();
        if (s_new.find('1') != string::npos) {
            cout << cal(s_new, '1') << endl;
        } else {
            cout << cal(s_new, '2') * 2 << endl;
        }
    }

public:
    static void main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        solve();
    }
};

int main() {
    Main::main();
    return 0;
}

