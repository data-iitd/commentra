#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

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
        cin >> n;
        string s;
        cin >> s;
        stringstream sb;
        for (int i = 1; i < n; i++) {
            sb << abs(s[i] - s[i - 1]);
        }
        string result = sb.str();
        if (n == 2) {
            cout << result[0] << endl;
            return;
        }
        if (result.find('1') != string::npos) {
            cout << cal(result, '1') << endl;
        } else {
            cout << cal(result, '2') * 2 << endl;
        }
    }

public:
    static void main() {
        Main().solve();
    }
};

int main() {
    Main::main();
    return 0;
}

// <END-OF-CODE>
